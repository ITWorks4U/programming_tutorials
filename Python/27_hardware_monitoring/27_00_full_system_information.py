# ---
# display your system hardware, CPU loadouts, ...
#
# required modules:
# - psutil
# - GPUtil
#
# it may happen, that this script is unable to run on your system,
# because some nested modules may unable to find and / or install
# ---

import platform as p
import os, re, subprocess as s
import psutil, GPUtil

tab = '\t'
quote = "'"

def analyze_cpu() -> str:
	"""
		Analyzing the CPU depending on the
		operating system and if it was able
		to scan the data.
	"""
	if p.system() == "Windows":
		return p.processor()
	#end if

	# usually in use for macOS
	# NOTE: never tested
	if p.system() == "Darwin":
		os.environ["PATH"] = os.environ["PATH"] + os.pathsep + "/usr/sbin"

		command ="sysctl -n machdep.cpu.brand_string"
		return s.check_output(command).strip()
	#end if

	if p.system() == "Linux":
		command = "cat /proc/cpuinfo"

		allInformations = s.check_output(command, shell=True).decode().strip()
		for line in allInformations.split("\n"):
			if "model name" in line:
				return re.sub( ".*model name.*:", "", line,1)
			#end if
		#end for
	#end if

	return "unable to detect your system CPU..."
#end function

def usage_cpu() -> str:
	"""
		returning current CPU usages
		depending on how many processes you're
		running at the moment, your machine, etc.
	"""
	load1, load2, load3 = psutil.getloadavg()
	return f"{(load1 / os.cpu_count()) * 100:.5}%{tab}{(load2 / os.cpu_count()) * 100:.5}%{tab}{(load3 / os.cpu_count()) * 100:.5}%"
#end function

def human_readable_size(bytes: int) -> str:
	"""
		transform bytes into a better format
	"""
	readable = ''

	#	it's primitive, but works :P

	if bytes < 1024:
		readable = f'{bytes:.5} B'
	elif bytes >= 1024 and bytes < (1024*1024):
		readable = f'{bytes/1024:.5} KB'
	elif bytes >= (1024*1024) and bytes < (1024*1024*1024):
		readable = f'{bytes/(1024*1024):.5} MB'
	elif bytes >= (1024*1024*1024) and bytes < (1024*1024*1024*1024):
		readable = f'{bytes/(1024*1024*1024):.5} GB'
	else:
		readable = f'{bytes/(1024*1024*1024/1024):.5} TB'
	#end if

	return readable
#end function

def get_cpu_temperature() -> float:
	"""
		Receiving the CPU temperature.

		ATTENTION: It may be, that the used key doesn't exist,
		so run the command psutil.sensors_temperatures() instead
		to reveal your requested information.
	"""
	return psutil.sensors_temperatures()["k10temp"][0].current
#end function

def get_gpu_informations() -> str:
	"""
		Do the same thing for your GPU.

		Make sure, that the GPUtil package
		has been installed on your system.
	"""

	all_system_informations: list = []

	# the available GPU RAM must be multiplicated with 1024,
	# otherwise a wrongly information returns

	for gpu in GPUtil.getGPUs():
		all_system_informations.append(f"""
{tab}{tab}name: {gpu.name}
{tab}{tab}driver: {gpu.driver}
{tab}{tab}temperature: {gpu.temperature} °C ({(gpu.temperature * 9/5) + 32} °F)
{tab}{tab}total RAM: {human_readable_size(gpu.memoryTotal * 1024)}
{tab}{tab}used: {human_readable_size(gpu.memoryUsed * 1024)}
{tab}{tab}free: {human_readable_size(gpu.memoryFree * 1024)}
""")
	#end for

	return "".join(all_system_informations)
#end function

def display_hardware():
	"""
		Hardware monitoring with Python 3.
	"""

	#	receive RAM informations
	ram = psutil.virtual_memory()

	allInformations = f"""
	You're running this script on a {quote}{p.system()}{quote} machine, with:

	machine type: {quote}{p.machine()}{quote}
	computer name: {quote}{p.node()}{quote}
	full OS name: {quote}{p.platform()}{quote}
	system release name: {quote}{p.release()}{quote}

	short summary:
	{p.uname()}

	hardware monitoring:
	CPU: {analyze_cpu()}
	# of cores: {os.cpu_count()}
	current CPU usages: {usage_cpu()}
	current temperature: {get_cpu_temperature()} °C

	RAM:
		total: {human_readable_size(ram[0])}
		available: {human_readable_size(ram[1])}
		currently in use: {ram[2]}%
		used: {human_readable_size(ram[3])}
		free: {human_readable_size(ram[4])}
		active: {human_readable_size(ram[5])}
		inactive: {human_readable_size(ram[6])}
		buffers: {human_readable_size(ram[7])}
		cached: {human_readable_size(ram[8])}
		shared: {human_readable_size(ram[9])}
		slab: {human_readable_size(ram[10])}

	GPU:{get_gpu_informations()}
	"""

	print(allInformations)
#end function

if __name__ == '__main__':
	display_hardware()
#end entry point