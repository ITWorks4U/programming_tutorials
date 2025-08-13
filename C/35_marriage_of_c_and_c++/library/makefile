compiler = gcc
c_flags = -g3 -Wall -fPIC -shared -o
lib_name = math_operations.so
source_file_cpp = math_operations.cpp
destination_path = ../run_example/

source_file_c = "math_operations.c"
asm_c = "math_assembly_c.asm"
asm_cpp = "math_assembly_cpp.asm"

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
	lib_name = math_operations.dylib
endif

all:	$(lib_name)

$(lib_name): $(source_file_cpp)
		@$(compiler) $(c_flags) $(lib_name) $(source_file_cpp)
		$(info Libary has successfully been built.)
		@mv $(lib_name) $(destination_path)
		@rm -f *.o

assembly:
		@$(compiler) $(c_flags) $(source_file_c) -S -o $(asm_c)
		@$(compiler) $(c_flags) $(source_file_cpp) -S -o $(asm_cpp)
		$(info created the assembly files instead)

clean:
		@rm -f $(destination_path)$(lib_name)
		$(info Removed the library.)

		@rm -f $(asm_c) $(asm_cpp)