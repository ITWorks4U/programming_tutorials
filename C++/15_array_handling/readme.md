#   array handling

>   **NOTE**:   A default array in C++ is almost identical to an array in C. C++ also comes with custom container collections, which are handled much better than raw arrays.

### C-arrays
-   arrays can store a fixed amount of elements for a certain data type
    -   sometimes an array may looks like a pointer, but this shall never be handled like a pointer
    -   this leads to an undefined behavior
        -   also exists in C++
-   by passing an array into a function, then you'll be very surprised

####    using a raw array, like:
```
int arr[] = {1,2,3,4,5};
```

### C++ - arrays
-   unlike to an "array", you'll use container collections, like:
    -   `array` (but is different to a raw array)
    -   `vector`

####    using an array container, like:
```
array<int32_t, 5> arr = {1, 2, 3, 4, 5};
```

####    using a vector container, like:
```
vector<int32_t> arr = {1, 2, 3, 4, 5};
```