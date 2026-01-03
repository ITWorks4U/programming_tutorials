#   Custom context manager
-   context managers are in use for memory management
    -   automatically releases the resource, when no longer needed
        -   same action, when an exception has been detected to release the resource from memory

basic example:
```
try:
    with open("file_to_use.txt") as src:
        print(src.readlines())
    
except Exception as e:
    print(e.args)
```

### define a custom context manger
-   can be realized by two ways:
    -   a class as a context manager
        -   define `__enter__`and `__exit__` methods, where:
        -   `__enter__` := allows to reserve a resource
        -   `__exit__` := when the resource is no longer planned to use, this will be released
    -   a function as a context manaher
        -   often in combination with `try`, `yield`, `except`
        -   e. g.: resource for a database communication and automatically release the resource, when the operation is done