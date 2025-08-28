#	Looping code over and over again

-   very often to repeat an instruction again and again until a condition is no longer given
-   often in combination with additional condition checks

### loop types in detail
| loop type | description |
| - | - |
| `while` | while a condition is `True`, this statement(s) repeats => make sure to use an exit condition to leave that loop |
| `for` | sequential iteration from a certain start value to its destination value |
| `"for each"` | in python identical to `for`; often in use for any collection |
| `goto` | basicly it's not possible to use that in Python, but with additional package(s) it's also possible |
| `recursion` | a function, which calls itself over and over again; almost similar to a while loop |

-   especially for a recursion, there're some points to know:
    -   unlike to a while loop, the application will crash, when no more free (virtual) space exists
    -   much faster than an iteration
    -   less code in contrast to a loop
    -   often used by mathematicians
    -   easier to implement, but harder to understand and much harder to debug

-   a recursion can be determined between:
| recursion type | effect |
| - | - |
| direct recursion | calling the function itself |
| indirect recursion | (at least two functions are required): function A calls function B, whereas B calls A |

### how to skip or leave a loop
-   continue
    -   continue your loop with the next possible step without care about the current step
-   break
    -   leave your loop immediately

######	attention
-   condition checks (also for loops, functions and classes) must have an indentation (white space **OR** tabs only)
-   be careful, which code is a part of a condition check (also for a loop, a function or a class); means: every code, which has the same indentation like the last code above, is automatically a part of this condition, loop, etc.