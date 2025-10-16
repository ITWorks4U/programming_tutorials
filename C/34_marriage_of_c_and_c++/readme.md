#   Working with C and also with C++

-   Sometimes it's required to build an application, which shall be run in C and C++, Working with C and C++ might sometimes not be easy.
-   Even the code has the typical C-style, your application might be able to build in **C++**, but not in **C**.
-   The main reason here is the certain source file: `math_operations.cpp`
    -   Since a C++ - file is in use the compiler (for C++ or C) will handle this file in a different way rather than the expected output.

####    detecting the difference between C and C++ compiling output

-   if you want to see a clean history about the reason, just run the compiler with: `-S` to generate an assembly file

### How to work for both compilers?

- to fix and handle that issue correctly, you must force he compiler to handle the functions as pure C-functions only
    - other types, like structs, enum (***NOT** enum-class*), union, macros might not be affected

- write:
```
	#ifdef __cplusplus
	extern "C" {
	#endif
		>>function(s) to use as like pure C functions<<
	#ifdef __cplusplus
	}
	#endif
```

-   however, this might look like awful
    -   there's a smarter way to handle this, just write instead:

```
	extern "C" {
		#include <your-header.h>
	}
```

######  Attention:
> Your header file MUST NOT contain any types, which existis in C++, but not in C.
> Thus, there're no class, template, namespace, ...