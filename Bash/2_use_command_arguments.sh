#---------
# using the additional arguments, when this script is in use
# => those starts with $0, $1, ...
# => fun fact: $0 is always your current used script
#
# => so you can run your script like: bash 2_use_command_arguments.sh a b c d e f g h <any other arguments here>
#---------

echo "used the first three arguments, if any: $0, $1, $2"
echo "total number of arguments: $#"

#---------
# special (positional) parameters
#
# $* => all given arguments are handled as a single string and can be combined into a loop
# $@ => all given arguments are handled each quoted individually
# $? => receiving the exit status of the last used command, where 0 = success, any other number: failure
# $$ => receiving the current process ID of the script or shell, which runs that script
#---------
# some examples:
#---------
for arg in "$*"; do
	# with $* the arguments are printed on the same line
	echo $arg
done

for arg in "$@"; do
	# with $@ the arguments are printed line by line
	echo "$arg"
done