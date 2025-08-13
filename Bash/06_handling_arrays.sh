#---------
# arrays may contain anything multiple times
#---------

var_a=10
var_b=20

array[0]=$var_a
array[1]=$var_a
array[2]=$var_b

# don't think, that this prints you [10, 10, 20]
# this prints [10[0], 10[1], 20[2]] instead
#echo "[$array[0], $array[1], $array[2]]"

# use this instead
echo "${array[*]}"

#---------
# define an empty array
# => in contrast to other languages, there's not a difference between
#    an array, a list, a set, a tuple
#---------
array_2=()
echo "${array_2[*]}"

#---------
# an array may contain anything
# hint: the elements in an array are usually not separated by a comma
# some shell interpreter might not know this
#---------
array_3=(10  11  12 13 14 3.141 "Hooray!")
echo "${array_3[*]}"