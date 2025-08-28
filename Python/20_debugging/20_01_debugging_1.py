import pdb

def suspicious():
	counter = 0

	while counter < 100:
		pass
	#end while
#end function

# you can also run a specific funtion for your debugging process, like:
# pdb.run('function'), where the name of the function must exist
# pdb.run('function(x=100)') with an argument and its value
#
# won't work
# pdb.run('suspicious()')

# use that instead:
# pdb.runcall(func: (**_P@runcall), *args: _P.args, **kwds: _P.kwargs)
# using your function to call
# if any arguments are required, move that to args or kwds, depending on your
# amount and type of arguments
pdb.runcall(suspicious)

# if your function takes counter as argument
# pdb.runcall(suspicious, 0)

# unlike to pdb.set_trace() no exception will be thrown by using 'quit'