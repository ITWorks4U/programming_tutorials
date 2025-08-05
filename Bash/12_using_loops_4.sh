#---------
# looping trough anything by using "recursion"
#---------
# ATTENTION(S):
# - In contrast to any loop instruction, a recursion may contain less code,
#   but it's more complex and this might also consume a huge amount of RAM + CPU usage
#   and it might also freeze your PC!
# - Similar to a while loop you must define an exit condition to leave the recursion!
# - A return statement can't handle a value outside of [0;255]!
# - Bash, and also other shell interpreters, can't handle a value by using return, because
#   this shows an exit code for the current function / last used application instead!
# - Instead of using return use echo.
#---------

#---------
# WRONG VERSION! (Even this might looks good enough to understand the syntax)
#---------
# function fibonacci_wrong() {
# 	if [ $1 -eq 0 ]; then
# 		return 0
# 	fi
#
# 	if [ $1 -eq 1 ]; then
# 		return 1
# 	fi
#
# 	return $(fibonacci_wrong ($1 - 1)) + $(fibonacci_wrong ($1 - 2))
# }
#---------
# correct version:
function fibonacci() {
	local n=$1

	if [ $n -eq 0 ] || [ $n -eq 1 ]; then
		echo "$n"
		return
	fi

	local n1=$(fibonacci $(( n - 1 )))
	local n2=$(fibonacci $(( n - 2 )))

	# important: by using echo in a recursion it's a bad idea not to cut out all
	# previous echo outputs => use the last echo output instead
	n1=$(echo "$n1" | tail -n 1)
	n2=$(echo "$n2" | tail -n 1)

	echo $(( n1 + n2 ))
}

# use a time measurment to figure out how long this could take
# SECONDS is a builtin variable and stores the time amount since the
# script was starting; this can be set to 0 to make a time measurment
# in the timespan t0 - t1
SECONDS=0

# remeber: the higher the value, the more RAM + CPU usage is in use
# in that case the upper limit is set to 15
for ((i=0; i<=15;i++)); do
	echo "fibonacci($i) = $(fibonacci $i)"
done

duration=$SECONDS
echo "total time amount: $((duration / 60)) min, $((duration % 60)) s"