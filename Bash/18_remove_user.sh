#---------
# Remove a user from the system.
# Works only, if you're user root or you are in the group of root.
#---------

if [ $(id -u) -eq 0 ]; then
	read -p "enter user account to remove: " user_name

	# try to find that user
	egrep "^$user_name" /etc/passwd > /dev/null

	if [ $? -eq 0 ]; then
		# the user has been found on the system

		#---------
		# remove that user and force recursively any files and folders, which has been
		# created by that user
		#---------
		# may not work (correctly), depending on the system you are working on
		#---------
		#deluser --force --remove-all-files $user_name
		userdel -rf $user_name
	else
		echo "The given user account $user_name was not found."
		exit 1
	fi
else
	echo "You're not logged in as root user."
	exit 1
fi