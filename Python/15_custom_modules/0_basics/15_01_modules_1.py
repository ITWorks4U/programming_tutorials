# ---
# using an alias
# unlike to write randmom.random()
# you're able to write r.random()
# ---
import random as r
pool = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!"§$%&/()=?_:;#'

# create a random string by using an amount of characters (n)
def random_string(n: int) -> str:
	return ''.join(r.choices(pool, k = n))
#end function

for c in (1,2,4,8,16,32,64,128,256):
	print(f'using {c} character(s) for: {random_string(c)}')
#end for