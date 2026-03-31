/*
* Contains common used socket implementation functions, like
* clean up the socket descriptors and allocated memory.
*/

#include <stdio.h>
#include "socket.h"

// ----------
// external, global implementations
// ----------
SocketOperations so = {UNSET_SOCKET_FD, UNSET_SOCKET_FD, false, false, false};
char current_os_name[BUFFER_OS_NAME];

// ----------
// function implementations
// ----------

void close_sockets(void) {
	// NOTE: the sockets must be initialized before, otherwise
	//       an error may appear on runtime
	if (so.on_server_socket_initialized) {
		FUNC_CLOSE_SOCKET(so.server_socket);
	}

	if (so.on_client_socket_initialized) {
		FUNC_CLOSE_SOCKET(so.client_socket);
	}
}

void clean_up_WSA(void) {
	#ifdef _WIN32
	/*
	* Cleans up the Winsock library before the application termiantes.
	* Similar to free() for Winsock resources.
	*
	* Deallocates resources Winsock was using and unloads the DLL,
	* if no other app is using it.
	*
	* NOTE: The cleanup will fail, if the WSA hasn't been initialized before.
	*/
	if (so.on_wsa_initialized) {
		WSACleanup();
	}
	#endif
}

void detect_current_os(void) {
	memset(current_os_name, '\0', BUFFER_OS_NAME);

	#ifndef _WIN32
	// not in use for Windows
	bool on_success = true;
	#endif

	#ifdef _WIN32
	// for any (expected) Windows machine

	// assuming, that the (full) OS name was unable to determine
	snprintf(current_os_name, BUFFER_OS_NAME, "Windows (unknown version)");

	typedef LONG(WINAPI* RtlGetVersionPtr)(PRTL_OSVERSIONINFOW);

	// Use the ANSI version to match the string literal
	HMODULE hMod = GetModuleHandleA("ntdll.dll");
	if (!hMod) {
		// printf("Failed to get module handle for ntdll.dll.\n");
		return;
	}

	RtlGetVersionPtr fn = (RtlGetVersionPtr)GetProcAddress(hMod, "RtlGetVersion");
	if (!fn) {
		// printf("Failed to get RtlGetVersion address.\n");
		return;
	}

	RTL_OSVERSIONINFOW rovi = { 0 };
	rovi.dwOSVersionInfoSize = sizeof(rovi);
	if (fn(&rovi) != 0) {
		// printf("RtlGetVersion failed.\n");
		return;
	}

	snprintf(
		current_os_name,
		BUFFER_OS_NAME,
		"Windows %lu.%lu (Build %lu)",
		rovi.dwMajorVersion,
		rovi.dwMinorVersion,
		rovi.dwBuildNumber
	);

	// printf("DEBUG: current_os_name = '%s'\n", current_os_name);
	#elif defined(__unix__) || defined(__linux__)
	// for any (expected) Linux machine
	FILE* fp = fopen("/etc/os-release", "r");

	if (fp == NULL) {
		snprintf(current_os_name, BUFFER_OS_NAME, "Linux (unknown distro)");
		on_success = false;
	}

	if (on_success) {
		char line[BUFFER_SIZE];
		memset(line, '\0', BUFFER_SIZE);

		while (fgets(line, sizeof(line), fp)) {
			if (strncmp(line, "PRETTY_NAME=", 12) == 0) {
				char* start = strchr(line, '=');
				if (start) {
					start++;
					if (*start == '\"') start++;
					char* end = strchr(start, '\"');
					if (end) *end = '\0';
					snprintf(current_os_name, BUFFER_OS_NAME, "%s", start);
					break;
				}
			}
		}

		fclose(fp);
	}
	#elif defined(__APPLE__) || defined(_MAC)
	// for any (expected) macOS
	FILE* fp = popen("sw_vers -productName && sw_vers -productVersion", "r");

	if (fp == NULL) {
		snprintf(current_os_name, BUFFER_OS_NAME, "macOS (unknown)");
		on_success = false;
	}

	if (on_success) {
		#define HALF_BUFFER (BUFFER_OS_NAME / 2)

		char name[HALF_BUFFER];
		char version[HALF_BUFFER];
		memset(name, '\0', HALF_BUFFER);
		memset(version, '\0', HALF_BUFFER);

		fgets(name, sizeof(name), fp);
		fgets(version, sizeof(version), fp);
		name[strcspn(name, "\n")] = 0;
		version[strcspn(version, "\n")] = 0;
		snprintf(current_os_name, BUFFER_OS_NAME, "%s %s", name, version);
		pclose(fp);
	}
	#else
	// in case of no Windows, Linux or macOS has been found
	snprintf(current_os_name, BUFFER_OS_NAME, "unknown OS");
	#endif
}