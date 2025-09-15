# ---
# Positional and keyword only arguments can also
# be combined together to force the user to call
# a function in a specific way.
# ---

def book_flight(origin: str, destination: str, /, travel_date: str, *, seat_class: int = 2) -> None:
	print(f"flight from {origin} to {destination}... travel date: {travel_date} on seat class: {seat_class}")
#end function

# works
book_flight("Germany", "France", travel_date="2025-01-01", seat_class=1)
book_flight("Finland", "Spain", "2024-08-03")

# won't work
# => the python interpreter complains about a wrong usage of this
# function call "Syntaxerror: positional argument follows keyword argument"
# book_flight(origin="USA", "Belgium", "2025-01-01")