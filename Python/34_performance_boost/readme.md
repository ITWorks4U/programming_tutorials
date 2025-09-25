#   Performing boost

-   very useful for simple implementations, which usually takes a huge amount of time, which is wasted, like:
    -   recursion
    -   database connection
    -   exponential time usage

-   this chapter demonstrates you how to boost up the fibonacci series with recursion to be able to calculate high numbers (n > 40) in a (very) short time

### examples
-   fibonacci series with raw recursion
    -   **not** recommended for high numbers (n > 40), unless you have enough time to waste ;-)
-   fibonacci series with a buffer to figure out, which number has already been calculated
    -   high performance boost (depending on the machine you're working on)
-   fibonacci series with @cache (from functools)
-   fibonacci series with @lru_cache (from functools)
-   fibonacci series with a loop instead
    -   in contrast to the other functions above this is a drastically performance boost within 8µs