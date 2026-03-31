#   time measurment
-   measure a time for a certain code instruction may help you out in some situations

>   **NOTE**:   This time measurment is only assumed to use in C. C++ may be use this as well, but it may also leads into an **undefined behavior**.

### required implementations
-   `time.h`, `math.h`
    -   on an UNIX system, the application shall be built with `-lm` for certain functions, otherwise the application can't be built
    -   on a Windows system this doesn't have an effect
-   using `clock_t`datatype with `clock()`function
-   calculating the estimated time in (floating point) seconds with (endtime - starttime) / `CLOCKS_PER_SEC`