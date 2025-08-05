#---------
# grep => global search for a regular expression and print out matched lines
# receive result(s) from a certain input or piped input
#---------
# by the way, those grep variants may also be used:
# egrep => extended grep => similar to grep, but allows to use additional regular expressions
# fgrep => fixed / fastest grep => might not work with a bunch of regular expressions like grep or egrep, but handles (large) files fast
# rgrep => recursive grep => for more deep search (and pain)
#---------

# list all files in your current directory and filter out all text files
ls -alh . | grep *.txt
echo "---------"

# get the current process of this running script, where grep is also part of the reuslt
ps -efl | grep "15_the_power_of_grep.sh"
echo "---------"

# to get rid grep as a result, use:
ps -efl | grep "15_the_power_of_grep.sh" | grep -v grep
echo "---------"

#---------
# using test_file.txt with grep, where regular expressions are also in use:
#
# expression | meaning                                              | example(s)
# ^          | print everything, which starts with the certain word | ^word
# $          | print everything, which ends with the certain word   | word$
# ^$         | print that full word only                            | ^word$
# .          | placeholder for any character                        | w.rd => word, ward, wird, ...
# .*         | placeholder for any amount of characters             | w.*rd => woooooooooooooord, ...
# []         | a character in a certain range                       | w[oa]rd => word, ward
# [^]        | no character in a certain range                      | w[^oa]rd => wbrd, wcrd, wdrd, ... (no word with "word" or "ward")
# +          | at least one time                                    | word[0-9]+ => word followed by a number of 0-9 must exist at least one time
# ?          | not or maximum of of once                            | word[0-9]? => word may followed by a number, but this is not necessary
# |          | alternative way                                      | word_a | word_b => "word_a" or "word_b" only
#---------
# examples:
# print everything from the test file line by line, which starts with "Lorem"
grep "^Lorem" test_file.txt
echo "---------"

# print everything line by line, which contains "fringilla"
grep "fringilla" test_file.txt
echo "---------"

# print everything line by line, which contains "nun" as a sub word
grep "nun.*" test_file.txt
echo "---------"

#---------
# look for a specific expression by using addional regular expressions, e. g.:
# "We are looking for any lorem expression in any text files."
# => Since only one text file with lorem... exists, the result set is small
#---------
grep -r "lorem" $(find . -name "*.txt")
echo "---------"

# similar above, but also print the source, where the sub word was found
grep -r "lorem"
echo "---------"