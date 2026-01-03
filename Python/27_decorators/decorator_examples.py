from decorators import (time_measurment_0, time_measurment_1, MAX_COUNTER)

# ---
# without an argument
# ---

@time_measurment_0
def counter_while() -> None:
	ctr: int = 0

	while ctr != MAX_COUNTER:
		ctr += 1
	#end while
#end function

@time_measurment_0
def counter_for() -> None:
	for _ in range(MAX_COUNTER):
		pass
	#end for
#end function

# ---
# with any argument(s)
# ---
@time_measurment_1
def handle_args(a: int = 1, b: int = 1, *args):
	result = a + b

	for arg in args:
		result += arg
	#end for

	return result
#end function

@time_measurment_1
def handle_kwargs(**kwargs):
	for key in kwargs.keys():
		print(f"{kwargs[key]}")
	# end for
# end function

@time_measurment_1
def counter_pythonic() -> None:
	# Who says, that a function without arguments
	# could not be used with time_measurment_1?
	_ = [i for i in range(MAX_COUNTER)]
#end function

def main() -> None:                                 # estimated time amount
	counter_while()                                 # 2.4 s
	counter_for()                                   # 1.2 s
	handle_args(1,2,3,4,5,6,7,8,9,0)                # 4 µs
	handle_args(*[i for i in range(MAX_COUNTER)])   # 3 s
	handle_kwargs(a="abc", b=123, c=[])             # 495 µs
	counter_pythonic()                              # 4.7 s
#end main

if __name__ == "__main__":
	main()
#end entry point