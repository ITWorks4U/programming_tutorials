#---------
# unlike if, elif, ..., else, fi use case instead,
# but this might also be a bit confuse you ^^
#---------
# basic syntax:
# case <variable> in
# <case_0>)
# #code;;
# <case_1>)
# code;;
# ...
# esac (yeah "case", but backwards)
#---------
# Every code in the case state must contain a semicolon twice!
#---------

var_a=10

case $var_a in
0)
	echo "$var_a must be 0, right?";;
5)
	echo "$var_a is possibly 5...";;
10)
	echo "$var_a is obviously 10!";;
*)
	echo "$var_a was different...";;
esac

#---------
# *) => default state, when the state(s) above doesn't match
#---------