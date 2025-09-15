# ---
# Keyword only arguments are in use to force
# the programmer to name the arguments.
#
# Those functions are often in use to offer
# a clean function definition.
# ---

def connect_to_database(*, host: str = "", port: int = 1337, database: str = "", user_name: str = "", password: str = "") -> None:
	print(f"connecting to database... {host}/{port}//{database}:{user_name}_{password}")
#end function

# works
connect_to_database(host="127.0.0.1", port=1337, database="postgres", user_name="user", password="pass")
connect_to_database()

# unable to work
# => the python compiler complains, that 0 positional arguments
# are required, but 5 were given (TypeError)
# connect_to_database("127.0.0.1", 1337, "postgres","user","pass")