#	macro to use everywhere
FLAGS=`pkg-config --cflags --libs gtk+-3.0` -export-dynamic

#	general sources and headers
SOURCES=source/gtk_full_tutorial.c source/gtk_event_listeners.c
HEADERS=header/gtk_full_tutorial.h

#	application target
TARGET=window.run

#
#	by using @ in front of a command, this will be suppressed on the console
#	$(info <text> displays a status message and looks much more professional)
#
#	attention: your information message will also be printed, even an error has been detected
#

#	building sequence
all:
				@gcc -g3 -Wall $(SOURCES) $(HEADERS) -o $(TARGET) $(FLAGS)
				$(info App "$(TARGET)" built.)

clean:
				@rm $(TARGET)
				$(info App "$(TARGET)" removed.)