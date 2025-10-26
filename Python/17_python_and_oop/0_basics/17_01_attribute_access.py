# ---
# By default in Python no access modifier,
# like "public", "protected", "private" or
# else exist. It's just a code style and this
# is often in use for general python programming.
#
# To determine, which attribute / method is "public",
# or "protected" (only), an underscore tells this
# to the programmer:
#
# <name>   := "public" attribute / class method
# _<name>  := "protected" attribute / class method
# _<name>_ := like above
#
# NOTE:    Python also allows you to modify the "protected / private"
#          members. There's no currently protection mode for that case.
#
# NOTE:    Sometimes an expression like: __<name> or
#          __<name>__ is marked as "real private", which
#          is NOT an idendification for a private member.
#          This is usually a "dunder method". (More in chapter advanced.)
#
# In summary, if a member / class method starts with a single underscore,
# then this is marked as "protected / private".
# ---

class Point:
	# "public"
	x = 0

	# "protected / private"
	_y = 0
#end class

def main() -> None:
	p = Point()
	print(f"p = [{p.x}, {p._y}]")

	# also be able to modify the members
	p.x = -2
	p._y = -4

	print(f"p = [{p.x}, {p._y}]")
#end main

if __name__ == "__main__":
	main()
#end entry point