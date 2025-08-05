#---------
# A shell script allows you to run multiple
# commands to handle different instructions.
#---------

# print the current directory
pwd

# get the current date
date

# list everything in your current directory
ls -al

# receive the current used terminal
echo "$TERM"

# Which user is currently using this script?
echo "current logged user is logged in: $LOGNAME"

# to combine some commands, like above, you have to use `<command>`
echo "Current system date: `date` and working directory: `pwd`"

#---------
# usually, date returns the date and time combined
# => to receive the time only, use:
#---------
clock_time=$(date +"%H:%M:%S")
echo "current system time: $clock_time"