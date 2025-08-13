#!/bin/bash

#---------
# How to use those shell scripts? Usually, in a command line / terminal you're
# using bash <script.sh>. Alternatively you can also run your script without
# using the command line. The shebang command on line 1 will do this instead.
# In that case those scripts are marked as an executable file itself.
#---------

#---------
# how to define variables
# => a variable can store any value, like word, expression, number, ...
# => a definition must be: <name>=<value>
# => no space is allowed between the assignment, otherwise the interpreter
#    does not know that definition
#---------
var_a=100
var_b="Hello World!"

#---------
# output
# => to use a variable, use $<variable> to receive the value of the certain variable
# => displaying the value of a variable can be used with echo $<variable>
#
# Both ways are able to use echo:
# => echo $variable
# => echo "$variable"
#
# What are the difference? With echo $variable only a single value can be used correctly.
# If your variable may contain more expressions, then use echo "$variable" instead.
# Since var_b contains "Hello World", it's no need to call echo "$var_b".
# You're welcome to use echo "$variable", because this is more robust. 
#---------
echo $var_a
echo $var_b