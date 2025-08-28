#	import main2, which also contains a main
import main2

if __name__ == '__main__':
	print('main1 is the real main')
else:
	print('no, main2 contains the real main...')
#end main

# Since main1.py will be used for the python interpreter,
# this main is the dominating part. Even main2.py also
# contains a main, this is not the main, we've called.

# it's more surprising, when you're importing main1 in main2,
# while main1 also imports main2:

# main1:
# 	import main2
# main2:
# 	import main1

# In that case we're importing main2, which imports main1, but
# unlike an endless loop, python automatically handles that.

# Finally, in the second main1, which is NOT identical to our first
# main1, it checks, if this is the main, which isn't. It goes back
# to main2, which is also not our real main and then we're back in
# our first main, which is the real main.