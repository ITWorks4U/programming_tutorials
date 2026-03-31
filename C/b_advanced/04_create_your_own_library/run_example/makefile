#	this makefile is required to link the main
#	with the created libary
#
#	to build the libary, take a look in libary_maker folder

# Compiler and flags
compiler = gcc
src_main = main.c
flags = -g3 -Wall
output = library_test.run

# Default library file
libary_file = library_maker.so

# Platform check for macOS vs Linux (never tested)
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
	libary_file = library_maker.dylib
endif

# Build target
all:
	@$(compiler) $(flags) -L. -o $(output) $(src_main) -l:$(libary_file)

#	if the command above won't result to success or the library is still unable
#	to find / load, try the instruction below
# 	@$(compiler) $(flags) -o $(output) $(src_main) -Wl,-rpath,'$ORIGIN' -ldl
	$(info Application has been built.)

# Clean target
clean:
	@rm -f $(output)
	$(info Application has been removed.)