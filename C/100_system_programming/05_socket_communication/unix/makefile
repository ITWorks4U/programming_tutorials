# build the server-client for an UNIX system

# --------------
# flags to set
# --------------
compiler = gcc
c_flags = -g3 -Wall -I../header -I../config -Wall -Wparentheses
config = ../config/config_reader.c
sock_impl = ../socket_impl/socket_implementations.c
server_unix = server_unix.run
client_unix = client_unix.run

# default target, when no argument is given
nothing:
	$(info usage: make [build_server | build_client | clean])
	$(info build_server = build the server application)
	$(info build_client = build the client application)
	$(info clean = removes the application(s))

build_server:
	@$(compiler) $(c_flags) server.c $(config) $(sock_impl) -o $(server_unix)
	$(info Server has been built.)

build_client:
	@$(compiler) $(c_flags) client.c $(config) $(sock_impl) -o $(client_unix)
	$(info Client has been built.)

clean:
	@rm -f $(server_unix)
	@rm -f $(client_unix)
	$(info Removed the application(s).)