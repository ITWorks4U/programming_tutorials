#---------
# usually, if statements allows you to run command(s), when a condition
# or a bunch of sub conditions returns true, however, the syntax is a bit... weired
#
# an if statement is defined as:
# if [ condition ]
#    then
#        command(s)
# fi
#
# The if statement must be closed with fi (finish if)!
#
# short form:
# if [ condition ]; then
#    command(s)
# fi
#
# more stripped form:
# if condition; then
#    command(s)
# fi
#---------

# simple comparisons:
# -eq <=> equal
# -ne <=> not equal
# -gt <=> greater than
# lt <=> lower than
# ...

#---------
# by using multiple sub conditions you can combine this with && or ||, where:
# && => and => all sub conditions must be true, to set the base condition to true as well
# || => or => at least one of the sub conditions must be true, to set the base condition to true as well
#
# Don't use a single expression like & or |, because:
# & => moves the current process into the background or moves a given output into another direction
# | => pipe => often in use with grep command
#---------

var_a=10
var_b=20

if [ $var_a -gt $var_b ]
	then
		echo "$var_a wins"
elif [ $var_a -lt $var_b ]
	then
		echo "$var_b wins"
else
	echo "$var_a == $var_b"
fi

#---------
# usually, it's not required to use a new indentation for the next command,
# but this gives you a more clean code
#---------
# it's recommended to use variables in quotations to prevent misinterpretations
#---------
# comaring strings, however, are a bit more complex
#---------

var_a="Hello World!"
var_b="Who is there?"

if [ "$var_a" == "$var_b" ]; then
echo "Both values contains the same content."
else
echo "Wait a minute..."
fi