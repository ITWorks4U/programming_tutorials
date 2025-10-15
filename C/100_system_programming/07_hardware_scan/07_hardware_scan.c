/*
* system programming in C
*
* Scanning the hardware components of your system. Each second the terminal / console screen will be updated.
* This application runs on Windows / UNIX.
*
* NOTE: Since C is hardware based, you can't access on the direct way to your CPU, RAM, GPU, ... in the usual way,
*       however, your OS (operating system) is able to gives you the required informations.
*
* NOTE: Depending on the given OS not every information is able to print to the console.
*       Furthermore, some functions are only available on Windows, where some other functions
*       are available on an UNIX system only.
*
* NOTE: Especially for GPU informations a basic way has been used for both systems.
*       Alternative ways would be OpenGL, Vulkan, nVidia or similar libraries, which
*       provides more detailed informations.
*
* NOTE: To be able to compile the application on a Windows machine, hit:
*       gcc.exe -g3 -Wall .\07_hardware_scan.c -o hardware_scan.exe -lkernel32 -lpsapi -lwbemuuid -ldxgi -ldxguid
*       This is required to load linked libraries.
*
*       On an UNIX system, tested with Linux Mint 22, a simple compile command, like:
*       gcc -g3 -Wall 07_hardware_scan.c -o hardware_scan.run
*       shall be enough to work with.
*
* NOTE: Since this application has been written in raw C, a C compiler only shall be used here.
*       It's not clear, if a C++ compiler is able to build this application and if no undefined
*       behavior(s) on runtime may appear. In that case if you try to compile this application with
*       a C++ compiler it will fail.
*
* ITWorks4U
*/

#ifdef __cplusplus
#error "This sample has been written in C only. Please use a C compiler."
#else

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include "07_hardware_scan.h"

#ifdef _WIN32
static FILETIME prev_idle_time, prev_kernel_time, prev_user_time;
#endif

/* required for signal handler */
static bool _on_continue = true;

// ----------
// internal functions
// ----------

static void _convert_to_timestamp(LARGE_UNSIGNED_NUMBER full_seconds) {
	int hours = full_seconds / 3600;
	int minutes = (full_seconds - (3600 * hours)) / 60;
	int seconds = full_seconds % 60;

	printf(" uptime since: %d hours, %d minutes, %d seconds\n", hours, minutes, seconds);
}

static double _convert_to_gigabytes(LARGE_UNSIGNED_NUMBER data) {
	return ((double)data / (1024*1024*1024));
}

// NOTE: Perhaps Windows uses an own signal handler instead...?
static void _handling_incoming_signals(int signum) {
	// printf("received signal: %d <=> %s\n", signum, strsignal(signum));
	// puts("terminating application...");

	#if _WIN32
	// just call system("cls");
	CLEAR_SCREEN;
	#else
	// use the unicode to clear the screen
	printf(CLEAR_SCREEN);
	#endif

	_on_continue = false;
}

#ifdef _WIN32
// only available on Windows
static void _determine_uptime_windows(void) {
	DWORDLONG uptime_in_ms = GetTickCount64();
	_convert_to_timestamp(uptime_in_ms / 1000);
}

static int _get_process_count(void) {
	DWORD processes[BUFFER], bytes_returned;

	if (!EnumProcesses(processes, sizeof(processes), &bytes_returned)) {
		perror("EnumProcesses failed");
		return -1;
	}

	// number of process IDs returned
	return bytes_returned / sizeof(DWORD);
}

ULARGE_INTEGER _filetime_to_ularge(FILETIME ft) {
	ULARGE_INTEGER li;
	li.LowPart = ft.dwLowDateTime;
	li.HighPart = ft.dwHighDateTime;
	return li;
}
#endif

// ----------
// public functions
// ----------

void print_memory_informations(void) {
	#ifdef _WIN32
	// for Windows
	MEMORYSTATUSEX memInfo;
	memInfo.dwLength = sizeof(memInfo);
	GlobalMemoryStatusEx(&memInfo);

	double totalPhys = _convert_to_gigabytes(memInfo.ullTotalPhys);
	double availPhys = _convert_to_gigabytes(memInfo.ullAvailPhys);


	printf(
		" total RAM: %.3f GB\n available RAM: %.3f GB\n memory load: %ld %%\n #processes: %d\n",
		totalPhys, availPhys, memInfo.dwMemoryLoad, _get_process_count()
	);
	#else
	// for UNIX
	struct sysinfo sys;

	if (sysinfo(&sys) < 0) {
		perror("sysinfo()");
		return;
	}

	_convert_to_timestamp(sys.uptime);

	printf(" 1, 5, 15 minute RAM load averages:  %lu, %lu, %lu\n", sys.loads[0], sys.loads[1], sys.loads[2]);
	printf(
		" total amount of RAM: %.3lf GB\n free RAM left: %.3lf GB\n amount of shared RAM: %.3lf GB\n",
		_convert_to_gigabytes(sys.totalram), _convert_to_gigabytes(sys.freeram), _convert_to_gigabytes(sys.sharedram)
	);
	printf(" memory used by buffers: %.3lf GB\n total swap space available: %.3lf\n", _convert_to_gigabytes(sys.bufferram), _convert_to_gigabytes(sys.totalswap));
	printf(" swap space left: %.3lf\n #of current processes: %u\n", _convert_to_gigabytes(sys.freeswap), sys.procs);
	#endif
}

#ifndef _WIN32
// only for UNIX

void print_cpu_informations(void) {
	bool on_success = true;
	FILE *cpu_info = NULL;
	
	if((cpu_info = fopen("/proc/cpuinfo", "r")) == NULL) {
		perror("fopen()");
		on_success = false;
	}

	if (on_success) {
		char *arg = NULL;
		size_t size = 0;

		bool freq_found = false, nbr_cores_found = false, model_name_found = false,
		cache_size_found = false, vendor_id_found = false;

		while(getdelim(&arg, &size, 0, cpu_info) != -1) {
			if (strstr(arg, "vendor_id") != NULL) {
				printf("%s\n", arg);
			}


			if (freq_found && nbr_cores_found && model_name_found && cache_size_found && vendor_id_found) {
				break;
			}
		}

		free(arg);
		arg = NULL;

		fclose(cpu_info);
		cpu_info = NULL;
	}
}
#endif

double calculate_cpu_usage(void) {
	#ifdef _WIN32
	// only for Windows

	FILETIME idle_time, kernel_time, user_time;

	if (!GetSystemTimes(&idle_time, &kernel_time, &user_time)) {
		return -1.0;
	}

	ULARGE_INTEGER idle = _filetime_to_ularge(idle_time);
	ULARGE_INTEGER kernel = _filetime_to_ularge(kernel_time);
	ULARGE_INTEGER user = _filetime_to_ularge(user_time);

	ULARGE_INTEGER prev_idle = _filetime_to_ularge(prev_idle_time);
	ULARGE_INTEGER prev_kernel = _filetime_to_ularge(prev_kernel_time);
	ULARGE_INTEGER prev_user = _filetime_to_ularge(prev_user_time);

	ULONGLONG sys_idle = idle.QuadPart - prev_idle.QuadPart;
	ULONGLONG sys_kernel = kernel.QuadPart - prev_kernel.QuadPart;
	ULONGLONG sys_user = user.QuadPart - prev_user.QuadPart;

	ULONGLONG sys_total = sys_kernel + sys_user;

	prev_idle_time = idle_time;
	prev_kernel_time = kernel_time;
	prev_user_time = user_time;

	if (sys_total == 0) {
		return 0.0;
	}

	return 100.0 * (1.0 - ((double)sys_idle / sys_total));

	#else
	// only for UNIX

	char file_buffer[BUFFER];
	memset(file_buffer, '\0', BUFFER);

	float load;
	int cpu_avg;

	if((cpu_avg = open("/proc/loadavg", O_RDONLY)) < 0) {
		perror("open()");
		exit(EXIT_FAILURE);
	}

	read(cpu_avg, file_buffer, sizeof(file_buffer) - 1);
	sscanf(file_buffer, "%f", &load);
	close(cpu_avg);

	// printf(" CPU load: %d %%\n", (int)(load * 100));
	return (double) load;
	#endif
}

void display_gpu_informations(void) {
	#ifdef _WIN32
	// only for Windows

	IDXGIFactory* pFactory = NULL;
	HRESULT hr = CreateDXGIFactory(&IID_IDXGIFactory, (void**)&pFactory);

	if (FAILED(hr)) {
		fprintf(stderr, "Failed to create DXGIFactory: 0x%lx\n", hr);
		return;
	}

	IDXGIAdapter* pAdapter = NULL;

	// just for a new line
	puts("");

	for(UINT i = 0; pFactory->lpVtbl->EnumAdapters(pFactory, i, &pAdapter) != DXGI_ERROR_NOT_FOUND; ++i) {
		DXGI_ADAPTER_DESC desc;
		pAdapter->lpVtbl->GetDesc(pAdapter, &desc);

		// Convert wide string to UTF-8 or just print wide string

		// NOTE: It may happen, that the current GPU name is unable to print to the
		//       console or some junk returns. In that case the wchar_t will be
		//       converted into a C-string instead.
		// wprintf(L"GPU %u: %s\n", i, desc.Description);
 
		char gpuName[BUFFER];
		WideCharToMultiByte(CP_UTF8, 0, desc.Description, -1, gpuName, sizeof(gpuName), NULL, NULL);
		printf("GPU Name: %s\n", gpuName);

		printf("Dedicated Video Memory:  %.2f GB\n", _convert_to_gigabytes((DWORDLONG) desc.DedicatedVideoMemory));
		printf("Dedicated System Memory: %.2f GB\n", _convert_to_gigabytes((DWORDLONG) desc.DedicatedSystemMemory));
		printf("Shared System Memory:    %.2f GB\n\n", _convert_to_gigabytes((DWORDLONG) desc.SharedSystemMemory));

		pAdapter->lpVtbl->Release(pAdapter);
	}

	pFactory->lpVtbl->Release(pFactory);
	#else
	// only for UNIX
	// NOTE: the used file "lspci" might not show every desired data

	FILE* fp = popen("lspci | grep -i 'vga\\|3d\\|display'", "r");
	if (fp == NULL) {
		perror("popen()");
		return;
	}

	char buffer[BUFFER + BUFFER];
	while (fgets(buffer, sizeof(buffer), fp) != NULL) {
		printf(" GPU Info: %s", buffer);
	}

	pclose(fp);
	#endif
}

// ----------
// main
// ----------

int main(void) {
	/*	in sysinfo almost all properties receives data in bytes only	*/
	// struct sysinfo sys;
	signal(SIGINT, _handling_incoming_signals);
	signal(SIGTERM, _handling_incoming_signals);

	#ifdef _WIN32
	GetSystemTimes(&prev_idle_time, &prev_kernel_time, &prev_user_time);
	#endif

	// for Windows x * 1000 => autmatically handled in header file
	// for UNIX x
	SLEEP_TIME(1);

	#ifndef _WIN32
	// detailed informations about your CPU(s) core(s)
	// only available outside of Windows
	//
	// NOTE: The informations could be large and will be displayed
	//       for only one second, because the while loop below is in use.
	print_cpu_informations();
	#endif

	/*	updating your output every 1 second	*/
	while(_on_continue) {
		#ifdef _WIN32
		CLEAR_SCREEN;
		#else
		printf(CLEAR_SCREEN);
		#endif

		printf(DESCRIPTION);
		printf("CPU load: %2.lf %%\n", calculate_cpu_usage());

		#ifdef _WIN32
		_determine_uptime_windows();
		#endif

		print_memory_informations();

		display_gpu_informations();

		SLEEP_TIME(1);
	}

	return EXIT_SUCCESS;
}
#endif