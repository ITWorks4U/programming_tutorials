# ---
# Not every signal is available on each system.
# This snippet below shows up which signals are available on your used system.
# ---

import signal
from platform import system

print(f"You're running this script on a {system()} system...")

for name in dir(signal):
	if name.startswith("SIG") and not name.startswith("SIG_"):
		print(name, getattr(signal, name))
	#end if
#end for
