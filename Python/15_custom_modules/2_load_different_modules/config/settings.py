try:
	#	only for main
	from misc.logging_to_somewhere import loggingSomething
	from misc.logging_type import LoggingType
except ImportError:
	#	only for settings.py
	import sys

	#NOTE:	It's not recommended to use the absolute path. This may work on your
	#		system. Does this also work on an another system as well? :-)

	#NOTE:	depending on from WHERE the settings.py is going to load the dynamic
	#		loaded path may also differ
	#
	#		example:	python[3|.exe] config/settings.py	=>	sys.path.append("misc")
	#					python[3|.exe] settings.py			=>	sys.path.append("../misc")

	#	using python[3|.exe] config/settings.py:
	sys.path.append("misc")
	from logging_to_somewhere import loggingSomething
	from logging_type import LoggingType
#end try

def loadConfig() -> None:
	loggingSomething("config file is loading", LoggingType.DEBUG)
	print(f'"loading config file..."')
#end function

if __name__ == '__main__':
	loadConfig()
#end entry point