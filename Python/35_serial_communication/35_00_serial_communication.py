# ---
# Serial communication in Python with a microcontroller, like an ESP32.
# The serial communication works with a plugged in USB cable. This can
# also be used with a direct wired UART cable connection, if you like. ;-)
#
# NOTE: Make sure you have installed the pyserial package module.
#
# NOTE: Never use a thread or a sub process for a bidirectional communication,
# because a serial communication is a critical resource. When this resource is
# in use for reading data, it can't be used for sending data at the same time.
# This causes a deadlock.
#
# NOTE: Make sure, that no other application blocks the COM port.
# Otherwise a serial communication is not available.
# ---

from time import sleep
from serial import Serial

def scan_all_serial_ports() -> bool:
	from platform import system
	from serial.tools.list_ports import comports
	all_serial_ports: list[str] = [comport.device for comport in comports()]

	summary = f"""> detected OS: {system()}
> available serial USB port(s): {all_serial_ports}"""

	print(summary)
	return len(all_serial_ports) > 0
#end function

def serial_communication(command: str) -> None:
	# port:     the USB port for the serial communication
	#           NOTE: COMx (x = 1,2,3,...) works only for Windows. On a UNIX system, like Linux, macOS, ...
	#           this shall be used instead: /dev/ttyUSBx (x = 0,1,2,3,...)
	# baudrate: how many characters per second are going to transfer
	# timeout:  how long a communcation is up to opened before the connection is
	#           automatically closed
	settings = {
		"port" : "COM6",
		"baudrate" : 115200,
		"timeout" : 0.1
	}

	try:
		with Serial(**settings) as s:
			if s.is_open:
				# NOTE: "\n" MUST be added, otherwise a communication MAY exist with a
				# high delay or nothing will be happen...
				s.write((command + "\n").encode())
				s.flush()

				# short sleep
				sleep(0.05)

				# NOTE: It may happen, that the micro controller returns anything instead
				# of the expected result.
				print(f"> received answer from ESP32: {s.read_all().decode().strip()}")
			#end if
		#end with
	except Exception as e:
		print(f"error by {serial_communication.__name__}: {e.args}")
	#end try
#end function

if __name__ == "__main__":
	# NOTE: The serial communication port may be different on your system.
	if scan_all_serial_ports():
		# get system info of the current micro controller
		serial_communication(command="system_info")
		sleep(2)

		# NOTE: "led_red_o[n|ff]" is a fixed command on the micro controller,
		# which turns on a red LED on or off
		serial_communication(command="led_red_on")
		sleep(1)
		serial_communication(command="led_red_off")
	else:
		print("> error: no serial ports detected...")
	#end if
#end entry point