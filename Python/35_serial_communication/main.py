# ---
# Serial communication in Python with a microcontroller, like an ESP32.
# The serial communication works with a plugged in USB cable. This can
# also be used with a direct wired UART cable connection, if you like. ;-)
#
# NOTE: Make sure you have installed the pyserial package module.
#
# NOTE: Never use a thread or a sub process for a bidirectional communication!
#       Because a serial communication is a critical resource. When this resource is
#       in use for reading data, it can't be used for sending data at the same time.
#       => This causes a deadlock.
#
# NOTE: Make sure, that no other application blocks the serial port.
#       Otherwise a serial communication is not available.
# ---

from time import sleep
from serial import Serial

valid_commands: list[str] = ["system_info", "green_on", "green_off", "yellow_on", "yellow_off", "red_on", "red_off", "q"]

def scan_all_serial_ports() -> None:
	from platform import system
	from serial.tools.list_ports import comports

	all_serial_ports: list[str] = [comport.device for comport in comports()]
	total_number: int = len(all_serial_ports)
	used_os: str = system()

	if total_number == 0:
		raise RuntimeError(f"No serial ports found on {used_os}.")
	#end if

	print(f"OS: {used_os} => available serial USB port(s): {all_serial_ports} (# ports: {total_number})")
#end function

def do_a_serial_communication(command: str, use_raw_data_ony: bool = False) -> None:
	# NOTE: COMx works only for Windows.  (x := 1,2,3,...,256)
	#       On a UNIX system, like: Linux, macOS, ... this shall be used instead:            /dev/ttyUSBy
	#       Depending on an another (UNIX) system, this could also be the desired address:   /dev/ttyACMy
	#       or this one:                                                                     /dev/ttySy
	#       (y := 0,1,2,3,...,63)
	#
	# port:     the USB port for the serial communication
	# baudrate: how many characters per second are going to transfer
	# timeout:  how long a communcation is up to opened before the connection is
	#           automatically closed

	from platform import system

	interface: str = {
		"Windows" : "COM6",            # Windows
		"Linux" : "/dev/ttyUSB0",      # Linux
		"Darwin" : "/dev/ttyUSB0"      # macOS (possible, never tested)
	}.get(system())

	if not interface:
		raise RuntimeError(f"error: unknown system detected...")
	#end if

	settings = {
		"port" : interface,
		"baudrate" : 9600,
		"timeout" : 0.1
	}

	if use_raw_data_ony:
		# NOTE: Only in use, if you want to transmit and handle
		#       raw data ony. On the microcontroller in commands.h:5
		#       the version is set to CURRENT_VERSION_V3
		raw_value = {
			valid_commands[0] : 0xA4,  # system info
			valid_commands[1] : 0x01,  # green_on
			valid_commands[2] : 0x02,  # green_off
			valid_commands[3] : 0x03,  # yellow_on
			valid_commands[4] : 0x04,  # yellow_off
			valid_commands[5] : 0x05,  # red_on
			valid_commands[6] : 0x06   # red_off
		}.get(command)
	#end if

	try:
		with Serial(**settings) as s:
			if s.is_open:
				if use_raw_data_ony:
					s.write(bytes([raw_value]))
				else:
					# NOTE: The destination board (used ESP32) handles the transmitted with \r\n.
					#       See: microcontroller/serial_communication.ino:21
					#       In that case make sure to add "\r\n", otherwise a communication MAY exist
					#       with a high delay or nothing might be happen...
					s.write((command + "\r\n").encode())
				#end if

				s.flush()

				# short sleep
				# NOTE: If the communicated messasge length is longer than the sleep
				#       mode, or if the microcontroller (ESP32 here) is too busy or
				#       else, if might happen, that you won't receive the correct or
				#       full message. It's much better to create two independent functions.
				#       One for write a message, one for read a message with a short delay
				#       between the two function calls.
				sleep(0.15)

				# NOTE: It may happen, that the micro controller returns anything instead
				# of the expected result.
				received: bytes = s.read_all()

				if received:
					answer: str = received.decode()
					print(f"> received answer from ESP32: {answer.strip()}")
				#end if
			#end if
		#end with
	except Exception as e:
		print(f"error by {do_a_serial_communication.__name__}: {e.args}")
	#end try
#end function

def main() -> None:
	print("Enter 'q' to quit.")

	while True:
		input_message: str = input("\nenter command: ")

		if input_message in valid_commands:
			if input_message == "q":
				break
			#end if

			do_a_serial_communication(command=input_message)
		else:
			print(f"given command: '{input_message}' unknown...")
		#end if
	#end while
#end main

if __name__ == "__main__":
	# optional signal handling events, if necessary
	from signal_handler import register_signal
	register_signal()

	# scan all available serial ports
	# => throws a RuntimeError, if no ports were found
	scan_all_serial_ports()

	main()
#end entry point