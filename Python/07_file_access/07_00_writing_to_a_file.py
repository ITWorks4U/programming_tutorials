# ---
# default way for writing
# ---

file_to_use: str = "result.txt"

# ---
# first option (without care of any failure)
# ---
destination = open(file=file_to_use, mode="w", encoding="utf-8")
_ = destination.write("This is a simple text!")
_ = destination.write("\n")
destination.writelines(["a,b,c,1,2,3,:-)"])
_ = destination.write("\n")
destination.close()

# ---
# second option (with care of a tiny bit of failure)
# ---
with open(file_to_use, "a") as destination:
	destination.writelines([str(i) for i in range(10)])
	_ = destination.write("\n")
# end with

# ---
# third way (unusual way, but possible, too)
# uses the print function instead
# ---
with open(file_to_use, encoding="ascii", mode='a') as destination:
	print("C", "C++", "Python", "C#", "Java", "...", file=destination)
#end with

# ---
# using binary form => writes é to the file
# attention: binary form won't accepting an encoding format
# ---
someBytes = b'\xC3\xA9'
with open(file_to_use, mode='+ab') as destination:
	destination.write(someBytes)
#end with