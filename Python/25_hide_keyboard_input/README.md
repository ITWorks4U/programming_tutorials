#   I see what I don't see

-   imagine, you're writing an application, which takes a username and a password for an authentification or else
-   usually, we're using input(promt: str) -> str function, to read from the keyboard, however, this is really unsecure, of course.
    -   especially by entering account informations it might be better to enter the data without seeing them
-   by default, Python does not comes with a function for that (at this moment)

### different kind of hiding the input

-   1.  install **getpass** package by `pip[3|.exe] install getpass`
```
import getpass
getpass.getpass(str: promt)
```

-   2.  install **maskpass** package by `pip[3|.exe] install maskpass`
```
import maskpass
maskpass.askpass(str: promt)
```

-   3.  install **getch** package by `pip[3|.exe] install getch`
```
import getch
getch.getch()
```