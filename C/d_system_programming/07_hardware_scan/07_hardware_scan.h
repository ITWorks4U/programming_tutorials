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

#ifndef HARDWARE_SCAN_H
#define HARDWARE_SCAN_H

#define	DESCRIPTION   "Press \"CTRL + C\" to exit.\n\n"
#define	BUFFER        256

#ifdef _WIN32
// for Windows only

#include <Windows.h>
#include <Psapi.h>    // for receiving the number of processes
#include <dxgi.h>     // for GPU informations
#include <wchar.h>    // some expressions are in wchar_t

// more in use for MS VS
// NOTE: Outside of MS VS a warning about those two expressions
//       below may appear. This can be ignored.
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "dxguid.lib")

#define CLEAR_SCREEN  system("cls")
#define SLEEP_TIME(x) (Sleep((x) * 1000))
#define LARGE_UNSIGNED_NUMBER DWORDLONG
#else
// for UNIX
#include <unistd.h>
#include <sys/sysinfo.h>
#include <sys/types.h>
#include <fcntl.h>

#define CLEAR_SCREEN  "\033[2J\033[1;1H"
#define SLEEP_TIME(x) (sleep((x)))
#define LARGE_UNSIGNED_NUMBER unsigned long
#endif

#ifndef _WIN32
// not available for Windows

/// @brief Display the CPU informations on stdout.
///
/// NOTE: It may contain a huge amount of data.
void print_cpu_informations(void);
#endif

/// @brief Calculate the current CPU usage in percent. The result may be
/// different to other modules, applications, ... depending on the power
/// of the used library, the amount of current running processes, etc.
/// @return the calculated CPU usage in percent.
double calculate_cpu_usage(void);

/// @brief Print the current RAM informations to stdout. Depending on the
/// used OS not every information is able to determine.
void print_memory_informations(void);

/// @brief Display the GPU informations to stdout.
/// Depending on the used OS and libraries, not every information
/// is able to determine.
void display_gpu_informations(void);

#endif