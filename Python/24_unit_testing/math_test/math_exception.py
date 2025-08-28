# use a custom exception for some mathematical
# failures
class MathException(Exception):
	def __init__(self, *args) -> None:
		super().__init__(*args)
	#end constructor
#end class