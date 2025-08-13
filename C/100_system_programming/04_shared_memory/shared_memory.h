#ifdef _WIN32
#error "These samples were written for UNIX/Linux/macOS only. Windows can't be used here."
#else

#ifndef SHARED_MEMORY_H
#define SHARED_MEMORY_H

#define	BUFFER_SIZE		256
#define	FILE_TO_USE		"shared_memory_file"
#define	PERMISSION		0644
#define	SIZE_TO_USE		65

#endif

#endif