# ---
# using pwinput
#
# similar to maskpass the mask comes with '*' by default
# ---

from pwinput import pwinput

user_name = input("enter username: ")
user_password = pwinput("enter password: ", mask="")

# any authentification here...
print(f"{user_name}, {user_password}")