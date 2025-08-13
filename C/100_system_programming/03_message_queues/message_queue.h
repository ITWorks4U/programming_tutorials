#ifdef _WIN32
#error "These samples were written for UNIX/Linux/macOS only. Windows can't be used here."
#else

#ifndef MESSAGE_QUEUE_H
#define MESSAGE_QUEUE_H

//	rw-r--r-- for the file
#define PERMISSION_OPTION	0644
#define BUFFER_SIZE	200
#define FILE_TO_USE	"message_queue_holder"
#define SIZE_TO_USE	65

struct MessageQueue {
	char m_text[BUFFER_SIZE];
};

#endif

#endif