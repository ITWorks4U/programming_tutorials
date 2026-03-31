#   code / runtime optimization
-   even C is fast, it's horribly slow, if you've allowed to be (very) slow
-   a tiny change may result into an another runtime state

####    examples
-   optimize the fibinacci series (recursion)
-   reduce the amount of incrementations inside a loop
-   ...

#####   fibonacci series
-   without optimization
    -   a number of 40...50...+ takes a horrible high time amount
```
int fibonacci_a(int n) {
    if (n < 2) {
        return n;
    }

    return fibonacci_a(n-1) + fibinacci_a(n-2);
}
```

-   with optimization
    -   here the upper boundary can be raised to 93, because even unsigned long long as a limitation value
```
#define MAX_ELEMENTS    100
#define ULL             unsigned long long

static ULL storage_buffer[MAX_ELEMENTS];

void init_storage_buffer(void) {
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        storage_buffer[i] = 0;
    }
}

ULL fibonacci_series(int nbr) {
    if (nbr <= 1) {
        return (ULL) nbr;
    }

    if (storage_buffer[nbr] != 0) {
        return storage_buffer[nbr];
    }

    storage_buffer[nbr] = fibonacci_series(nbr - 1) + fibonacci_series(nbr - 2);
    return storage_buffer[nbr];
}
```