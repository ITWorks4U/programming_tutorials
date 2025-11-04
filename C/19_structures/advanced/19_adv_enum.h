#ifndef ADV_ENUM_H
#define ADV_ENUM_H

// usual way for an enumeration
enum Status {
	A, B, C
};

// also possible, but hardly used
enum {
	D, E, F
} those_status;

// sometimes in use to define and use constant expressions
// instead of using #define directive
enum {
	G, H, I
};

// customized status to access to their members J,K,L only
typedef enum {
	J, K, L
} CustomStatus;

// bonus: only available in C++
#ifdef __cplusplus
// READY is defined twice, but C++ enum class can handle those easily

enum class StatusA {
	READY, WORK, STOPPED 
};

enum class StatusB {
	READY, RUNNING, HALTED, FAILED
};
#endif

#endif