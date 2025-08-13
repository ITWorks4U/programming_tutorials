#	a simple makefile which allows
#	you to build a project very easy
#
#	left side:		target(s)
#	right side:		command(s) for the given target(s)
#
#	Every target may contain dependencies.
#
#	the top target will be used automatically
#	by calling 'make'
#
#	attention:
#	- this is available for Linux / macOS only
#	- Windows (with mingw) may also be able to use that file (without a file extention),
#	  but there's no guarantee to work with. Use the batch or powershell file instead.
#
#	A makefile can also use definitions, which are defined before. (not shown here)
#	You're also welcome to import a foreign makefile content to that makefile (not shown here)

#target		dependency for target 'all'
all:		16_use_a_makefile.o
			gcc -g3 -Wall 16_use_a_makefile.o -o app.run

#			a custom information for build process
			$(info app.run successfully built.)
#			other messages by: $(warning text) $(error text)

#			removing object file => no longer in use
#			adding '@' in front of a command, the output
#			is suppressed
#
#			-f in rm: if the file does not exist, no error is printed
			@rm -f 16_use_a_makefile.o

16_use_a_makefile.o:	16_use_a_makefile.c
						gcc -c 16_use_a_makefile.c

#target must not be called 'clean', but it's often used
clean:
			rm -f app.run