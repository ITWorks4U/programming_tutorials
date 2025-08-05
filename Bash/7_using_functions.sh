#---------
# a function allows you to define a (block of) code and run it over and over again
#---------
# IMPORTANT: A function must be defined first before calling it.
#---------
# basic syntax:
# function <name>() {}
#
# calling function:
# <name_of_function> [argument(s)]
#---------

function do_something() {
	echo "Number of used arguments: $#"
	echo "arguments were: $@"
}

function increment_temp() {
	# local is optional, but helps you to determine, that >>this<<
	# temp variable is planned to use in this function only
	local temp=0

	# multiple ways to increment temp
	((temp++))
	temp=$(($temp + 1))
	temp=`expr $temp + 1`

	return $temp
}

#---------
# calling
#---------

do_something
do_something 1 2 3 "Hello World!"

increment_temp

# How assign the return state of a function?
#
# NOT this way:
# value=$(increment_temp)
#
# use this way:
value=$?
echo "value = $value"