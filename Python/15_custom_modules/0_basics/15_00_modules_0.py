# ---
# import everything from a module
# it also allows to import multiple modules
# ---
import os, platform
print(f"You're running this script on this location: {os.getcwd()}.")
print(f"Your system: {platform.system()}, release: {platform.release()}, version: {platform.version()}")