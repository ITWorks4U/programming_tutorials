# ---
# using getpass module
# ---

from getpass import getpass

user_name = input("enter username: ")
user_password = getpass("enter password: ")

# any authentification here...
print(f"{user_name}, {user_password}")