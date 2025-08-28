#   Nothing to see here?

-   not really
-   `None` is similar to other languages with `void`, but this is not always given
    -   can also be used to define a default state or just for "nothing"
-   often used for:
    -   functions
    -   presets

### examples
```
undefined = None
print("You will see this:", undefined)
```

```
def nothing_to_see_here() -> None:
    pass

for i in range(10):
    print(f"{i}: {nothing_to_see_here()}")
```