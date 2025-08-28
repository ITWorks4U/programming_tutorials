collection = ["abc", 123, True, False, None]

def will_not_work(collection: list) -> None:
	# will not work, because: "collection is parameter and global"
	# this is unable to use with the global keyword

	# global collection

	print(f"collection before modification: {collection}")
	
	collection = [753, "42 is the answer"]
	print(f"collection after modification: {collection}")

	# since collection will be assinged with new data, when
	# the function is left, the origin data will be restored,
	# because >>this internal collection<< is a copy of
	# the >>external collection<<

#end function

print(f"collection before function call: {collection}")
will_not_work(collection)
print(f"collection after modification: {collection}")