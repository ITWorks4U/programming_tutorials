# ---
# Mastermind: Guess for colors, which has been
# created randomly by the system.
#
# version 2:
#  - still fixed colors
#  - user enters four colors (can be different or multiple)
#  - analyzing first input with first color; if this doesn"t
#    match, then check the first color with the second, third
#    and fourth color(s) instead; similar to the other colors
#  - counting points for the correct color on the correct
#    position and also the correct color on a wrong position
#  - unlike to version 1 we don"t get an information, if the
#    first color on the first position is correct or not,
#    which makes the game harder for us
#  - runs the application once only
# ---

# "random" colors
c1 = "red"
c2 = "green"
c3 = "blue"
c4 = "yellow"

# the correct color on the correct position
points_for_color_and_position = 0

# the correct color on a wrong position
points_for_colors_only = 0

# determines, which system color has already
# been handled and which not
done_c1 = False
done_c2 = False
done_c3 = False
done_c4 = False

# same for user guess
done_g1 = False
done_g2 = False
done_g3 = False
done_g4 = False

print("***Mastermind***")
print("Try to guess the correct colors. These colors are valid: red, yellow, green, blue, black, white, brown, magenta")

# entering four colors, separated by a space
colors = input("Enter four colors. These are separated by a single space: ").split()
color1 = colors[0]
color2 = colors[1]
color3 = colors[2]
color4 = colors[3]

print("Analyzing...")

# First check, if the first color is
# on the first position. Similar for
# color 2 on the second position etc.
#
# If true, points_for_color_and_position is
# raised by 1.
if color1 == c1:
	points_for_color_and_position += 1
	done_c1 = True
	done_g1 = True
#end if

if color2 == c2:
	points_for_color_and_position += 1
	done_c2 = True
	done_g2 = True
#end if

if color3 == c3:
	points_for_color_and_position += 1
	done_c3 = True
	done_g3 = True
#end if

if color4 == c4:
	points_for_color_and_position += 1
	done_c4 = True
	done_g4 = True
#end if

# Second check, if the first color is
# not on the first position, but maybe
# on the second, third and/or fourth
# position.
#
# for the other colors, we"re checking:
# - second color: position 1, 3, 4
# - third color: position 1, 2, 4
# - fourth color: position 1, 2, 3
#
# If true, points_for_colors_only is raised
# by one.
if not done_c1:
	if not done_g2 and color1 == c2:
		points_for_colors_only += 1
		done_c1 = True
		done_g2 = True
	#end if

	if not done_g3 and c1 == color3:
		points_for_colors_only += 1
		done_c1 = True
		done_g3 = True
	#end if
	
	if not done_g4 and c1 == color4:
		points_for_colors_only += 1
		done_c1 = True
		done_g4 = True
	#end if
#end if

if not done_c2:
	if not done_g1 and c2 == color1:
		points_for_colors_only += 1
		done_c2 = True
		done_g1 = True
	#end if
	
	if not done_g3 and c2 == color3:
		points_for_colors_only += 1
		done_c2 = True
		done_g3 = True
	#end if
	
	if not done_g4 and c2 == color4:
		points_for_colors_only += 1
		done_c2 = True
		done_g4 = True
	#end if
#end if

if not done_c3:
	if not done_g1 and c3 == color1:
		points_for_colors_only += 1
		done_c3 = True
		done_g1 = True
	#end if
	
	if not done_g2 and c3 == color2:
		points_for_colors_only += 1
		done_c3 = True
		done_g2 = True
	#end if
	
	if not done_g4 and c3 == color4:
		points_for_colors_only += 1
		done_c3 = True
		done_g4 = True
	#end if
#end if

if not done_c4:
	if not done_g1 and c4 == color1:
		points_for_colors_only += 1
		done_c4 = True
		done_g1 = True
	#end if
	
	if not done_g2 and c4 == color2:
		points_for_colors_only += 1
		done_c4 = True
		done_g2 = True
	#end if
	
	if not done_g3 and c4 == color3:
		points_for_colors_only += 1
		done_c4 = True
		done_g3 = True
	#end if
#end if

# summary
if points_for_color_and_position == 4:
	print(f"Impressive. You've guessed the correct colors and their positions!")
else:
	print(f"correct color and position: {points_for_color_and_position}")
	print(f"correct colors only: {points_for_colors_only}")
#end if

print("Game over.")