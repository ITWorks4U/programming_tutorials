#	macro to use everywhere
FLAGS=`pkg-config --cflags --libs gtk+-3.0` -export-dynamic

#	general sources and headers
SOURCES=source/gtk_full_tutorial.c source/gtk_event_listeners.c source/extern.c
HEADERS=header/gtk_full_tutorial.h

#	application target
TARGET=window.run
TARGET_WIN=window.exe

#	building sequence
all:
				@gcc -g3 -Wall $(SOURCES) $(HEADERS) -o $(TARGET) $(FLAGS)
				$(info App "$(TARGET)" built.)

clean:
				@rm $(TARGET)
				$(info App "$(TARGET)" removed.)

#	NOT TESTED UNDER WINDOWS!
app_win:
				@gcc -g3 -Wall $(SOURCES) $(HEADERS) -o $(TARGET_WIN) $(FLAGS)
				$(info App "$(TARGET_WIN)" built.)

clean_win:
				@del $(TARGET_WIN)
				$(info App "$(TARGET_WIN)" removed.)