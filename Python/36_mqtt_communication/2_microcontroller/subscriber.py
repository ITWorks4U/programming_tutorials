# ---
# MQTT subsriber.
#
# Subscribe / Receive a message from a channel from the
# MQTT server (broker). Any publisher, even the subsriber itself,
# is able to send a message, when the channel name is identical.
#
# NOTE: By default a MQTT communication is able without any authentification.
# This sample, however, requires an authentification to work with.
#
# ---

from sys import path
from os.path import abspath, join, dirname
path.append(abspath(join(dirname(__file__), "..")))

from mqtt_settings.settings_reader import ConfigReaderMQTT
from mqtt_settings.handling_signals import register_sigals

# 3rd-party MQTT module
from paho.mqtt.client import Client, CallbackAPIVersion

# NOTE: required for the subscriber, because the MQTT client was unable
# to subscribe to a channel from main, therefore the subcription to
# a channel is realized in the on_connect() callback function
_cfg_reader = ConfigReaderMQTT()

# ---
# callback functions
# ---

# callback function, when a message from a subscriber channel
# has been received => required
#
# NOTE: message only is in use
def on_message(client, userdata, message) -> None:
	receiver = {
		"message": str(message.payload.decode()),
		"topic": message.topic,
		"QOS": str(message.qos)
	}

	print(receiver)
#end function

# callback function, when the connection to the broker has been
# established => required
#
# NOTE: return_code only is in use
def on_connect(client, userdata, flags, return_code, properties) -> None:
	print(f"rc = {return_code}")
#end function

# callback function, when a subscription attempt to the
# broker is in use => optional
#
# NOTE: reason_code_list only is in use
def on_subscribe(client, userdata, mid, reason_code_list, properties) -> None:
	print(f"=> {reason_code_list[0]}")
#end function

# ---
# main
# ---

def main() -> None:
	client_settings = {
		"callback_api_version" : CallbackAPIVersion.VERSION2,   # NOTE: CallbackAPIVersion.VERSION2 means, that this runs with MQTT version 5
		"client_id" : "subscriber",                             # the client ID; can be anything, as long as, the ID differs to the publisher
		"clean_session" : True                                  # ensures to have a clean message, when the publisher has been disconnected previously
	}

	client = Client(**client_settings)
	client.on_connect = on_connect
	client.on_message = on_message
	client.on_subscribe = on_subscribe

	_cfg_reader.read_settings()

	# NOTE: The communication may be possible only, if a valid user and
	# password is required (like here)
	current_user: str = list(_cfg_reader.users.keys())[1]
	current_passwd: str = list(_cfg_reader.users.values())[1]
	client.username_pw_set(current_user, current_passwd)

	client.connect(host=_cfg_reader.host_names[2], port=int(_cfg_reader.ports[0]))

	for subscription_channel in _cfg_reader.subscriber_channels:
		client.subscribe(subscription_channel)
	#end for
	client.loop_forever()
#end function

if __name__ == "__main__":
	register_sigals()
	main()
#end entry point