#---------
# looping trough anything by using "for" syntax
#---------
# basic syntax:
# for <variable> in <collection>
# do
# #code
# done
#
# short version:
# for <variable> in <collection>; do
# #code
# done
#
# more short version:
# for <variable> in <collection>; do; #code; done
#---------

array=(0,1,2,3,4,5,6,7,8,9,'a','b','c')

#---------
for i in ${array[*]}
do
	echo "i = $i"
done
#---------
for i in 0 1 2 3 4 5 6 7 8 9; do
	echo "i = $i"
done
#---------
# similar syntax in common programming languages
for ((i=0; i<10; i++)); do
	echo "i = $i"
done
#---------
# unlike to elements of an array, your home directory can also be used:
for f in $HOME/*; do
	# display every visible file and folder in your home directory
	echo "$f"
done
#---------