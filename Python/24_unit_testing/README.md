#   Unit Testing

-   allows you to test your script / application for a bunch of certain conditions, like:
    -   "What will happen, if this instruction got a wrong argument?"
    -   "Was that supposed to do?"
    -   "Does this exception raise?"
    -   ...

-   deep tests allows you to find and fix bugs or logical issues, which may used as a backdoor instead
-   test cases are isolated tests for a specific situation to check, if an expected error appears to handle it correctly

###  modules to offer you unit testing

| module | description | additional informations |
| - | - | - |
| `unittest` | built-in Python module | similar to JUnit in Java |
| `pytest` | third party framework | `pip install pytest` |
| `doctest` | tests embedded in docstrings | useful for simple cases and documentation |

###    unittest:
-   use a class, which tests different cases
-   can expect a successful, failed test
-   tests can be skipped
-   test cases **must** start with `test_` prefix, otherwise this test case does not run
-   does not come with a test order by your own
    -   the tests are running in the alphabetical order instead

| result states | description |
| - | - |
| .	| executed successfully |
| x	| expected a failure |
| u	| unexpected successes |
| s | skipped that test |
| F	| failed test |
| E | thrown exception, which has not been catched |

-   run with:
    -   `python <file>`
        -   default usage for unittest
    -   `python -m unittest <file>`
        -   can be more in use, if the unit tests are in a different folder and may result into an error, if the used modules can't be found
```
import unittest

def add(a, b):
    return a + b

class TestAddFunction(unittest.TestCase):
    def test_add_positive_numbers(self):
        self.assertEqual(add(2, 3), 5)

    def test_add_negative_numbers(self):
        self.assertEqual(add(-1, -1), -2)

    def test_add_zero(self):
        self.assertEqual(add(0, 0), 0)

if __name__ == '__main__':
    unittest.main()
```

### pytest:
-   can also run unittest test cases
-   run with:
    -   `pytest <file>`
    -   `py.test.exe <file>`
        -   on Windows this is more often in use

```
# test_add.py

def add(a, b):
    return a + b

def test_add_positive_numbers():
    assert add(2, 3) == 5

def test_add_negative_numbers():
    assert add(-1, -1) == -2

def test_add_zero():
    assert add(0, 0) == 0
```

| result states | description |
| - | - |
| .	| executed successfully |
| x	| expected a failure |
| X	| unexpected successes |
| s | skipped that test |
| F	| failed test |
| E | thrown exception, which has not been catched |


### doctest:
-   run with `python test_file.py`

```
def add(a, b):
    """
    Adds two numbers together.

    >>> add(2, 3)
    5
    >>> add(-1, -1)
    -2
    >>> add(0, 0)
    0
    """
    return a + b

if __name__ == "__main__":
    import doctest
    doctest.testmod(verbose=True)
```

| result states | description |
| - | - |
| .	| executed successfully |
| F	| failed test |

>   **NOTE**:
>   -   by default no output exists (silent execution)
>       -   verbose mode: `doctest.testmethod(verbose=True)`