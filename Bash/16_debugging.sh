#---------
# debugging a shell script may help you out to find logical issues
#---------
# tracing your current script by using:
# bash -x <script>
value=100
print "$value"

#---------
# set a debug flag by using "trap" command, where the shell may handle that
# command different
#
# trap 'command(s)' DEBUG'
# for ksh (korn shell) only: trap 'command(s)' ERR
#
# run this script with that command:
# 'printf "debugging on line number $LINENO :-> "; read line; eval $line' DEBUG
#
# where this code below is in use:
#---------
counter=10

while [ $counter -lt 10 ]; do
	echo "counter = $counter"
done

# Since counter is set to 10, the condition "while counter is lower than 10" is never true
# and this loop is never in use.
