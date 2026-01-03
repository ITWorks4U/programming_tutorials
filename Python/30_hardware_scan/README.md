#   Monitoring

-   allows you an overview about your system
    -   drive scan (1)
    -   hardware scan (2)

>   **NOTE**: These scripts has been tested on Windows 11 Professional, Linux Mint 22.1, Raspberry Pi.

####    scan drives
-   scan each detected (hard) drive (HDD, SSD, M2, USB, ...)
    -   total space
    -   used space
    -   free space left

####    scan hardware
-   scan the detected hardware on your system as much as possible, like:
    -   detected CPU(s)
    -   CPU(s) amount
    -   RAM usage
    -   detected GPU(s)

>   **NOTE:** These modules are required: psutil, GPUtil

```
pip[3|.exe] install psutil
pip[3|.exe] install GPUtil
```