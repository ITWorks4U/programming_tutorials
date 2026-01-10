compiler = gcc
c_flags = -g3 -Wall -fPIC -shared -o
lib_name = lib.so
source_file = lib.c
destination_path = ../

#	this shall be checked, if macOS is in use instead (never tested)
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
	lib_name = lib.dylib
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