from misc.logging_to_somewhere import loggingSomething
from misc.logging_type import LoggingType
from config.settings import loadConfig

loadConfig()
loggingSomething(message="next steps here...", logType=LoggingType.DEBUG)