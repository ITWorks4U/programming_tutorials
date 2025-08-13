#	macro to use everywhere
FLAGS=`pkg-config --cflags --libs gtk+-3.0` -export-dynamic

#	general sources and headers
SOURCES=source/gtk_full_tutorial.c source/gtk_event_listeners.c source/gtk_boolean.c
HEADERS=header/gtk_full_tutorial.h

#	application target
TARGET=window.run

#	building sequence
all:
				@gcc -g3 -Wall $(SOURCES) $(HEADERS) -o $(TARGET) $(FLAGS)
				$(info App "$(TARGET)" built.)

clean:
				@rm $(TARGET)
				$(info App "$(TARGET)" removed.)