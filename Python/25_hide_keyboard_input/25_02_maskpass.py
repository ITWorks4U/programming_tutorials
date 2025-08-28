# ---
# using maskpass
#
# by default, maskpass comes with a mask of '*' and shall be
# replaced with "" to hide the length of characters
# ---

from maskpass import askpass

user_name = input("enter username: ")
user_password = askpass("enter password: ", mask="")

# any authentification here...
print(f"{user_name}, {user_password}")