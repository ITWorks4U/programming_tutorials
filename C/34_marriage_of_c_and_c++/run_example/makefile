# compiler_c and flags
compiler_c_c = gcc
compiler_cpp = g++
src_main_c = main.c
src_main_cpp = main.cpp
flags = -g3 -Wall
output = math_operations.run

# Default library file
libary_file = math_operations.so

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
	libary_file = math_operations.dylib
endif

all:
	$(error Use target_c or target_cpp.)

target_c:
	@$(compiler_c) $(flags) -L. -o $(output) $(src_main_c) -l:$(libary_file)
	$(info Application has been built.)

target_cpp:
	@$(compiler_cpp) $(flags) -L. -o $(output) $(src_main_cpp) -l:$(libary_file)
	$(info Application has been built.)

# Clean target
clean:
	@rm -f $(output)
	$(info Application has been removed.)