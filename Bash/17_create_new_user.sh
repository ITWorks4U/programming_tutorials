#---------
# create a new user to work with
# This script works only, if you're root or you are in the group of root.
#---------

if [ $(id -u) -eq 0 ]; then
	# you are root user here => The new user name and user password will be printed to stdout!
	read -p "add new user name: " user_name
	read -p "add new user password: " user_password

	# check, if this user may already exist (supress results here with redirecting to /dev/null)
	egrep "^$user_name" /etc/passwd > /dev/null
	if [ $? - eq 0 ]; then
		echo "$user_name already exists in the system. Aborting..."
		exit 1
	else
		# encrypt the given user password
		encrypted_password=$(perl -e 'print crypt($ARGV[0], "password")' $user_password)

		# add the new user to the system with the encrypted password
		useradd -mp $encrypted_password $user_name

		if [ $? -eq 0 ]; then
			echo "new user $user_name has been created"
		else
			echo "failed to add the new user $user_name..."
			exit 1
		fi
	fi
else
	#you're not logged in as root user
	echo "You're not logged in as root user."
	exit 1
fi