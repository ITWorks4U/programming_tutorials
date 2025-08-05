#---------
# looping trough anything by using "select" loop
#
# Unlike to for, while, until, or a recursion a select works
# different. With "select" every data from an array will be printed
# to the console with a number from 0, 1, ..., n-1.
#
# Then you're asked for entering one of those numbers (0,1,2,...,n-1)
# to use the value itself. This can be repeated over and over again.
#
# To break that loop, use Ctrl + C or use a value, which leaves that "loop".
#---------
# basic syntax:
# select <variable> in <collection>
# do
# #code
# done
#---------
# this is also similar to for loop, but more often in use for collections in
# combination with case syntax
#---------

array=(0 1 2 3 4 5 6 7 8 9 'a' 'b')

select n in ${array[@]}
do
	# Checks, if n might be a number or not
	# realized by using a regular expression and
	# by using =~ combined
	#
	# By the way, the short form: ^\d+$ won't (often) work correctly.
	if [[ "$n" =~ ^[0-9]+$ ]]; then
		remainder=$((n % 2))

		case $remainder in
			0)
				echo "$n is an even number";;
			1)
				echo "$n is an odd number";;
		esac
	else
		echo "$n was not an integer..."
	fi
done