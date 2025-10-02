# ---
# MQTT publisher.
#
# Publish / send a message by a channel to the MQTT server (broker).
# Any client, even the publisher itself, is able to receive a message,
# when the channel name is identical.
#
# NOTE: By default a MQTT communication is able without any authentification.
# This sample, however, requires an authentification to work with.
#
# ---

from time import sleep

# ---
# required to be able to import everything from mqtt_settings folder
from sys import path
from os.path import abspath, join, dirname
path.append(abspath(join(dirname(__file__), "..")))

from mqtt_settings.settings_reader import ConfigReaderMQTT
from mqtt_settings.handling_signals import register_sigals
# ---

# 3rd-party MQTT module
from paho.mqtt.client import Client, CallbackAPIVersion

# ---
# callback function
# ---

# callback function, when a message has been published => optional
def on_publish(client, userdata, mid, reason_code, properties) -> None:
	summary = {
		"client" : client,
		"userdata" : userdata,
		"message id" : mid,
		"reason_code" : reason_code,
		"properties" : properties
	}

	print(summary)
#end function

# ---
# main
# ---

def main() -> None:
	client_settings = {
		"callback_api_version" : CallbackAPIVersion.VERSION2,   # NOTE: CallbackAPIVersion.VERSION2 means, that this runs with MQTT version 5
		"client_id" : "publisher",                              # the client ID; can be anything, as long as, the ID differs to the subscriber
		"clean_session" : True                                  # ensures to have a clean message, when the publisher has been disconnected previously
	}

	client = Client(**client_settings)

	cfg_reader = ConfigReaderMQTT()
	cfg_reader.read_settings()

	# NOTE: The communication may be possible only, if a valid user and
	# password is required (like here)
	current_user: str = list(cfg_reader.users.keys())[0]
	current_passwd: str = list(cfg_reader.users.values())[0]

	client.username_pw_set(current_user, current_passwd)
	client.connect(host=cfg_reader.host_names[0], port=int(cfg_reader.ports[0]))

	# register a callback function => optional
	client.on_publish = on_publish

	counter: int = 0
	while True:
		message = f"message #{counter}"
		client.publish(cfg_reader.publisher_channels[0], payload=message)

		counter += 1
		sleep(0.5)
	#end while
#end main

if __name__ == "__main__":
	register_sigals()
	main()
#end entry point