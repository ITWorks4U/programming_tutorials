#---------
# advanced if statements for numeric, string comparisons, ...
#---------

var_a=10
var_b=20

# you can use this:
if [[ "$var_a" -gt "$var_b" ]]; then
echo "$var_a is greater than $var_b."
else
echo "$var_b is greater than $var_a."
fi

# or this:
if (( $var_a > $var_b )); then
echo "$var_a is greater than $var_b."
else
echo "$var_b is greater than $var_a."
fi

#---------
# string comparisons...
#---------
var_a="Hello World!"
var_b="Who is there?"

# usual way:
if [ "$var_a" == "$var_b" ];
then
	echo "$var_a == $var_b"
else
	echo "erm... nope"
fi

# use this instead:
# => allows to compare strings more efficient
# => allows to use regular expressions
# => patter matching
# => ...
if [[ "$var_a" == hello* ]]; then
echo "$var_a starts with hello..."
else
echo "$var_a does not start with hello..."
fi