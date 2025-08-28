#!/usr/bin/python3
# shebang command above

# ------------
# Python 3 is really easy to learn. It allows you to start
# to programm without any deep knowledge.
#
# Usually, you run your python script by using the python interpreter, like:
# python[3.|exe] <your_python_file.py>
#
# Sometimes it may be important to run your script as a standalone
# "application". In that case the shebang command (first line) is
# required. Usually, you don't need that command and this will be
# in this file only.
#
# Python is an interpreter language, which means, you don't have
# to do any datatype definitions. Every variable, here an object,
# can easy be defined and also reinterpreted by any other value.
#
# However, there are >some< points to know:
# - by using blocks, like conditions, loops, functions, ... it's required
#   to know, which command/s is/are part of the block
#   => see more in the certain section folders, like decicion making, loops, ...
# - in contrast to any other language, it's neccessary to know
#   what kind of indention you're using; there're two of them:
#   (1) using space bar(s)
#   (2) using tab(s)
#
#   because Python won't agree a mix of both on one block,
#   you must use one of them
#
# hint:
# - you also can display whitespace(s) and tab(s) (almost any editor):
#   view -> display whitespaces (or similar expression)
#   in Visual Studio (used here), go to the gear symbol (left corner)
#   => settings => in the search bar, hit "whitespace", be default the
#   second entry "render whitespace" shall appear and set the setting to "all"
#
# - bonus: hit "insert spaces" in the search bar to decide, if a tab will
#   automatically be converted into space(s), if you like
#
# - all blocks are used with tab (4 spaces)
#
# Finally, have fun with Python 3!
# ------------

# simple print command
# everything is a word on output or by reading from keyboard / file
print("Hello World!")
print("1, 2, 3")

# declaring an integer (in Python 3 any integer is a long type without a limitation)
number = 123
print(number)

# now it's a float type (redefinition of number)
number = 123.456789
print(number)

# convert it to a word
number = str(number)
print(number)