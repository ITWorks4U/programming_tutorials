from re import match

# the whole expression (buffer) must pass trough the filter, where
#
# match:
#  - starts from left only
#
# search:
#  - looking anywhere in the buffer,
#    if the filter can be spotted there
#
#  returns a Match[str] object, which can be used for
#  a simple condition check or None for mismatch

email_pattern: str = r"^[a-z]{1,10}@(gmail|gmx|hotmail)\.(com|info|de)$"

buffer = input("verify your email-address: ")
if match(email_pattern, buffer):
	print("email-address is verified")
else:
	print("email-address has not the expected format")
#end if