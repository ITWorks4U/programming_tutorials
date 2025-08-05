#---------
# I/O operations by using a file for our purpose.
#---------

# create a file first => usually, this file does not exist yet
# and usually a check, if this file may exist, would also help
# you out, unless, you don't care about the previous content
#---------
# (over-)write anything to the file: >
# appending new content to the file: >>

touch list_of_all_files_in_home.txt

# (over-)writing into a file
ls -alh $HOME > list_of_all_files_in_home.txt

# reading from that file
# cat, more, less, ...
cat list_of_all_files_in_home.txt

# appending any other content to a file
touch result.txt

array=(0 1 2 3 4 5 6 7 8 9)

for n in ${array[*]}
do
    remainder=$((n % 2))

	case $remainder in
		1)
			echo "$n is an odd number" >> result.txt;;
		0)
			echo "$n is an even number" >> result.txt;;
	esac
done