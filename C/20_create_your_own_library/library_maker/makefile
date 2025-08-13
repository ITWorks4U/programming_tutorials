#	makefile for UNIX/Linux/macOS only,
#	where a *.so file is only created here
#
#	If you want to create a library for Windows, use the batch or powershell file instead.

compiler = gcc
c_flags = -g3 -Wall -fPIC -shared -o
lib_name = library_maker.so
source_file = library_maker.c
destination_path = ../run_example/

#	this shall be checked, if macOS is in use instead (never tested)
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
	lib_name = libary_maker.dylib
endif

all:	$(lib_name)

$(lib_name): $(source_file)
		@$(compiler) $(c_flags) $(lib_name) $(source_file)
		$(info Libary has successfully been built.)
		@mv $(lib_name) $(destination_path)
		@rm -f *.o

clean:
		@rm -f $(destination_path)$(lib_name)
		$(info Removed the library.)