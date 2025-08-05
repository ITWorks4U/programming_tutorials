#---------
# I/O operations by using keyboard for input, where your console
# is in use for output, which was already be in use before.
#---------

input_value=""
read -s -p "enter a value: " input_value
echo "your input: $input_value"

#---------
# read: read from the keyboard, where:
# -s: "silent" => echo input will be suppressed (newline might also be suppressed)
# -p: promt command => tell the user, that there's an input required and what kind of input is required as well
#---------
# more informations: https://linuxcommand.org/lc3_man_pages/readh.html
#---------