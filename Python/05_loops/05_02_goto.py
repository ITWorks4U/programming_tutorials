# ---
# usually, Python does not comes with a goto statement and
# you should also not use goto statements, because this
# causes "spaghetti code" and noone has any clue, what kind
# of mess this results to
# ---
# this can be emulated by a package, like goto-statement
# use:
# pip[3|.exe] install goto-statement
# => on a Linux system it may happen, that this module is unable
# install by pip; in that case this shall be installed by
# sudo apt install python3-goto-statement
# ---

from goto import with_goto

# ---
# attention: it may happen, that this code
# won't be run, if the interpreter can't handle
# with this instruction, even goto-statement module
# has been installed on your system
# ---

@with_goto
def goto_sample():
	ctr: int = 0

	# define a label to jump to that label,
	# if required
	label .start

	print(f"ctr = {ctr}")
	ctr += 1

	if ctr < 10:
		goto .start
	#end if

	print("finally, I am here!")
#end function

goto_sample()