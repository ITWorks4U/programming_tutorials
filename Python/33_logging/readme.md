#   Log to a file

-   much better than printing to stdout / stderr
-   allows to create and handle a log file for your professional purpose
    -   can be managed by:
        -   your own file handling
            -   make sure, that the file can be created / written, ...
            -   by default, no limitation of a file size or a huge amount of log files needs to be handled, no dayly rotation exists, but can be implemented by your own, ...
            -   ...
    -   using logging module
        -   allows to let create a log file and appending messages
        -   offers:
            -   a dayly rotation
            -   file size rotation
            -   the number of log files to keep up

### how to log:
-   writing your own log file handler
-   using logging module

### example

- init a new log sequence

```
import logging
from logging.handlers import TimedRotatingFileHandler

log_handler = TimedRotatingFileHandler("logging.log")
formatter = logging.Formatter("%(asctime)s - %(levelname)s - %(message)s")
log_handler.setFormatter(formatter)

logging.basicConfig(level=logging.DEBUG, handlers=[log_handler])
```

-   write to log
```
logging.info("This is a simple log message.")
logging.warning("This is a warning.")
logging.error("This is an error.")
```