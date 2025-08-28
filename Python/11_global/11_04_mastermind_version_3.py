# ---
# Mastermind: Guess for colors, which has been
# created randomly by the system.
#
# version 3:
#  - random colors by system
#  - using collections instead of multiple single objects
#  - using functions for more professional skill with
#    the ability for a better code maintenance
#  - user enters four colors (can be different or multiple)
#  - analyzing each color on each possible position
#  - counting points for the correct color on the correct
#    position and also the correct color on a wrong position
#  - unlike to version 2 since we"re using real random colors,
#    we also have no idea which colors are in use
#  - adding a loop to have 5 guesses
#  - finally, the correct collection will be printed at the
#    end of the application
# ---

# required for random colors
from random import choice

# holds four random colors
system_colors: list[str] = []

# in use for random color selection,
# where the number represents the random color
random_number_collection: tuple[int] = (0,1,2,3,4,5,6,7)

# number of guesses
guess_counter: int = 0

# holds our four color guesses
guess_collection_user: list[str] = []

# Since you are using python version 10+, you can also
# use the match key for a switch-case.
#
# To make sure to play the game with a lower python 3
# version, we're using the "classic way".
def create_random_color(colorID: int) -> None:
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

	system_colors.append(cs.get(colorID))
#end function

# in use four "real" random colors
for _ in range(4):
	create_random_color(choice(random_number_collection))
#end for

# define collections and variables for the game, which
# must be able to modify inside of analyze_guesses() function
colors_done = [False, False, False, False]
colors_guesses = [False, False, False, False]

points_for_color_and_position = 0
points_for_colors_only = 0
already_guessed = False

# Analyzing the guesses.
#
# In combination with two loops we"re comparing
# color i (system color) with color j (guessed color).
# If true, then this color is marked as "done".
#
# In the second stage we try to figure out if the
# first color might be on position 2, 3, and/or 4.
# Similar to the other colors.
def analyze_guesses() -> None:
	global points_for_color_and_position
	global points_for_colors_only
	global already_guessed

	#	step 1: check, if the system color on position i is equal to
	#			the color from input on position j
	for i in range(len(system_colors)):
		for j in range(len(guess_collection_user)):

			#	also check, if this color has not already been
			#	guessed before
			on_check = (
				system_colors[i] == guess_collection_user[j] and
				not colors_done[i] and not colors_guesses[j]
			)

			if on_check:
				points_for_color_and_position += 1
				colors_done[i] = True
				colors_guesses[j] = True
			#end if
		#end for
	#end for

	# step 2:	check, which color might be on an another position instead
	for i in range(len(system_colors)):
		if not colors_done[i]:
			for j in range(len(guess_collection_user)):

				# To avoid to handle the color on the same
				# position (again). Since we know, that the color j on position i is identical,
				# we will skip this step.
				if i == j:
					continue
				#end if

				# we also check, if the current guessed color in
				# combination with the next color is given
				on_check = (
					not colors_guesses[j] and guess_collection_user[j] == system_colors[i] and
					not colors_done[i] and not colors_guesses[j]
				)

				if on_check:
					points_for_colors_only += 1
					colors_done[i] = True
					colors_guesses[j] = True
				#end if
			#end for
		#end if
	#end for

	# if we also have reached the maximum points for all (correct) colors,
	# this flag will be set to true
	if points_for_color_and_position == 4 or points_for_colors_only == 4:
		already_guessed = True
	#end if

	# optional: print the current state to the console
	print(f"correct color and position: {points_for_color_and_position}")
	print(f"correct colors only: {points_for_colors_only}")
#end function

# main application
print("***Mastermind***")
print("Try to guess the correct colors. These colors are valid: red, yellow, green, blue, black, white, brown, magenta")
print("You have up to 5 guesses! Good luck!")

# We're using up to 5 rounds to guess
# the correct color combination.
for i in range(5):
	guess_counter += 1
	print(f"current guess: {guess_counter}")
	guess_collection_user = input("Enter four colors. These are separated by a single space: ").split()
	print("Analyzing...")
	analyze_guesses()

	# "if already_guessed:" works, too
	if already_guessed == True:
		break
	#end if
#end for

# finally, print the current combination
# to the console
print()
print("********************")
print(f"These were the current colors: {system_colors}")
print("********************")
print()

print("Game over.")