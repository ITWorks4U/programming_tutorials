#---------
# looping trough anything by using "until" loop
#---------
# similar to while loop, where the condition says:
# "Until a condition is no longer given, loop..." 
#
# In other words: "While the condition is not true, repeat."
#---------
# basic syntax:
# until [ condition(s) ]
# do
# #code
# done
#---------

counter=0

until [ $counter -ge 10 ]; do
	echo "counter = $counter"
	((counter++))
done