#   main function for Python

-   usually, Python don't comes with a main function
    -   for simple projects, a main function is also not needed
    -   for complex applications a main function is recommended to know where to start your python script
        -   every python script may have a "main function", whereas this "main" is not identical to "main()"
        -   even a main() is defined, it won't be handled as a main() in other languages, like C, C++, C#, Java, ...
            -   it's "just" a normal function, which can hold n instructions, but this is not going to call automatically
-   to define a "main", often called: "entry point", you have to use a condidtion check
    -   fun fact: you also do not need that, but it looks more professional

###	How to define a "main()"
-   write:

```
if __name__ == '__main__':
    #code....
```

> __name__: is the file name, which shall be the current "main", when it's in use by the python interpreter

### different behavior for main
-   use two files, named `main1.py`and `main2.py`
-   main1.py:
```
import main2

if __name__ == '__main__':
    print('main1 is the real main')
else:
    print('no, main2 contains the real main...')
#end main
```
-   main2.py:
```
import main1

if __name__ == '__main__':
    print('main2 is the real main')
else:
    print('no, main1 contains the real main...')
#end main
```

-   depending on which file is launched by the Python interpreter, this is "the main" for the application and may result different behavior or results

### arguments for main
-   using `sys` module
    -   contains a list of arguments
    -   first argument (`sys.argv[0]`) is **always** your own python file

```
from sys import argv

if __name__ == '__main__':
    print(f'arguments passed: {len(argv)}')

    for i,a in enumerate(argv):
        print(f'argument {i}: {a}')
```