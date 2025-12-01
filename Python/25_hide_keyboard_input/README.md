#   I see what I don't see

-   imagine, you're writing an application, which takes a username and a password for an authentification or else
-   usually, we're using input(promt: str) -> str function, to read from the keyboard, however, this is really unsecure, of course.
    -   especially by entering account informations it might be better to enter the data without seeing them
-   by default, Python does not comes with a function for that (at this moment)
>   **NOTE:** These modules could already exist on your system, otherwise those must be installed with pip.


### different kind of hiding the input

-   install **getpass** package by `pip[3|.exe] install getpass`
```
from getpass import getpass
getpass(promt: str)
```

-   install **maskpass** package by `pip[3|.exe] install maskpass`
```
from maskpass import askpass
askpass(promt: str, mask: str)
```

-   install **getch** package by `pip[3|.exe] install getch`
>   **NOTE:** This module could be unable to install on your system.
```
from getch import getch
getch()
```

-   install **pwinput** package by `pip[3|.exe] install pwinput`
```
from pwinput import pwinput
pwinput(promt: str, mask: str)
```