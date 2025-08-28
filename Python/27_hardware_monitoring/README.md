#   Purpose

-   monitoring the installed hardware and their software on your system
    -   __attention:__
        -   this script has been written and ran under a Linux Mint 21.1 Cinnamon only
        -   it may be unable to run on other systems

### required packages
-   psutil
-   GPUtil

```
pip[3|.exe] install psutil
pip[3|.exe] install GPUtil
```

### offers:
-   scan your current system information
-   checks the CPU usage
-   checks how many memory of RAM has been installed and which is in use
-   checks, if available, which graphic card(s) is(are) installed and displaying the driver version