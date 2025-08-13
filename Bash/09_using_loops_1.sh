#---------
# looping trough anything by using "while" syntax
#---------
# basic syntax:
# while [ condition(s) ]
# do
# #code
# done
#
# In contrast to for you must ensure to leave the loop at any time,
# when the condition in the head does no longer be true!
#---------
counter=0

while [ $counter -lt 10 ]
do
	echo "counter = $counter"
	((counter++))
done

#---------
# by using a "while true" loop, write:
#---------
while :
do
	echo "counter = $counter"
	((counter--))

	# make sure to leave the infinite loop with an
	# additional condition check, like:
	if [ $counter -eq 0 ]
	then
		break
	fi
done