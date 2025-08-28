# ---
# Mastermind: Guess for colors, which has been
# created randomly by the system.
#
# version 4:
# - using a class
# - handling signal
# - using multiline strings
# - fixed logic error on color analyzing
# ---

from random import choice
from signal import SIGINT, signal

class MasterMind():
	def __init__(self) -> None:
		"""
			Initialize a new instance of the game mastermind.
		"""

		# private objects
		self._system_colors: list[str] = []
		self._random_number_collection: tuple[int] = (0,1,2,3,4,5,6,7)
		self._guess_counter: int = 0
		self._guess_collection_user: list[str] = []
		self._stop_game: bool = False
		self._color_collection: tuple[str] = ("red", "yellow", "green", "blue", "orange", "purple", "black", "white")

		#	public objects
		self.already_guessed: bool = False
		self.colors_done: list[bool] = [False, False, False, False]
		self.colors_guesses: list[bool] = [False, False, False, False]
		self.points_for_color_and_position: int = 0
		self.points_for_colors_only: int = 0

		for _ in range(4):
			self._create_random_color(choice(self._random_number_collection))
		#end for
	#end constructor

	def _create_random_color(self, color_id: int) -> None:
		"""
			On start four colors are selected
			randomly, thus you don"t know,
			which colors are in use.
		"""
		cs = {
			0: "red",
			1: "yellow",
			2: "green",
			3: "blue",
			4: "orange",
			5: "purple",
			6: "black",
			7: "white"
		}

		self._system_colors.append(cs.get(color_id))
	#end method

	def _analyze_guesses(self) -> None:
		"""
			Analyzing the four colors and try
			to figure out, which one of these
			colors are on the correct position
			and also exist.
		"""
		for i in range(len(self._system_colors)):
			for j in range(len(self._guess_collection_user)):

				# if the current color has not been guessed yet
				on_check = (
					self._system_colors[i] == self._guess_collection_user[j] and
					not self.colors_done[i] and not self.colors_guesses[j]
				)

				if on_check:
					self.points_for_color_and_position += 1
					self.colors_done[i] = True
					self.colors_guesses[j] = True
				#end if
			#end for
		#end for

		for i in range(len(self._system_colors)):
			if not self.colors_done[i]:
				for j in range(len(self._guess_collection_user)):
					if i == j:
						continue
					#end if

					on_check = (
						not self.colors_guesses[j] and self._guess_collection_user[j] == self._system_colors[i] and
						not self.colors_done[i] and not self.colors_guesses[j]
					)

					if on_check:
						self.points_for_colors_only += 1
						self.colors_done[i] = True
						self.colors_guesses[j] = True
					#end if
				#end for
			#end if
		#end for

		if self.points_for_color_and_position == 4 or self.points_for_colors_only == 4:
			self.already_guessed = True
		#end if
	#end method

	def _on_correct_length(self) -> bool:
		"""
			Make sure, that we have exactly 4 elements
		"""
		return len(self._guess_collection_user) == 4
	#end method

	def _check_input(self) -> None:
		"""
			Check, if the four elements are located in
			the defined color collection. If not, then
			the game ends earlier.
		"""
		for color in self._guess_collection_user:
			if color not in self._color_collection:
				self._stop_game = True
			#end if
		#end for

		if self._stop_game:
			print("ERROR: No four colors have been typed in or the colors were wrongly typed in... Exit game.")
		#end if
	#end method

	def start_game(self):
		"""
			Start the game.
		"""
		for _ in range(5):
			self._guess_counter += 1
			print(f"current guess: {self._guess_counter}")
			
			self._guess_collection_user = input("enter four colors: ").split()

			if not self._on_correct_length():
				print("ERROR: There are no four colors detected. Exiting game...")
				self._stop_game = True
			#end if

			self._check_input()

			if self.already_guessed or self._stop_game:
				break
			#end if

			print("Analyzing...")
			self._analyze_guesses()

			print(f"current correct guesses: {self.points_for_color_and_position}, correct color: {self.points_for_colors_only}")
		#end for
	#end method

	def print_summary(self) -> str:
		return f"""
********************
These were the current colors: {self._system_colors}
********************
"""
	#end method

	# if Ctrl + C (^C) has been pressed,
	# the game ends earlier with exit code 0
	def handle_signal_interrupt(self, signal, frame):
		self._stop_game = True
	#end function
#end class

def main():
	# registering signal
	signal(signalnum=SIGINT, handler=m.handle_signal_interrupt)

	title = f"""***Mastermind***
These colors are valid: red, yellow, green, blue, black, white, brown, magenta
Enter four colors separated by a space bar to try to figure out which colors are in use.
You have up to 5 guesses! Good luck!
"""
	print(title)

	# new instance for the game
	m = MasterMind()

	# starting the game
	m.start_game()

	# only, if you still have no idea which colors
	# has been chosen
	if not m.already_guessed:
		print(m.print_summary())
	#end if
#end main

if __name__ == "__main__":
	main()
	print("Game over.")
#end entry point