#   Benchmark
-   checks, how fast end efficient a code runs
    -   often used for complex algorithm with other dependencies to check, how fast or slow the application runs
    -   also sometimes in comparison with other languages, like C, C++, ...
-   usually, a benchmark contains:
    -   time amount
    -   CPU / RAM usage
    -   ...

### different ways to use a benchmark
| function / class | import command | usage | example |
| - | - | - | - |
| datetime | `from datetime import datetime` | measuring durations in real-word time | `#1` |
| time | `from time import time` | measuring on low level (seconds since epoch) | `#2` |
| perf_counter | `from time import perf_conter` | high precision timer | `#3` |
| process_time | `from time import process_time` | CPU time only (without sleep time) | `#4` |
| timeit | `from timeit import timeit` | accurate, repeatable benchmark | `#5` |
| perf_counter_ns | `from time import perf_counter_ns` | since Python 3.7; precision scan in nanoseconds | `#6` |
| process_time_ns | `from time import process_time_ns` | CPU time amount in nanoseconds | - |
| timedelta | `from datetime import timedelta` | prints a human readable time amount only; works in combination with timeit | `#7` |
| Timer | `from timeit import Timer` | in use, if a statement, here: function / class method call, requires argument(s) | `#8` |

> NOTE: Almost all benchmark samples are in use with timedelta and timeit. Benchmark with arguments are also using Timer class.

#### examples:

- `#1`:
```
from datetime import datetime

start = datetime.now()
# ... some code ...
end = datetime.now()

# returns timedelta, where no formatted output exists here
duration = end - start
```

- `#2`:
```
from time import time

start = time()
# ... some code ...
end = time()

# returns elapsed time amount in seconds only
print(f"Elapsed: {end - start} seconds")
```

- `#3`:
```
from time import perf_counter

start = perf_counter()
# ... some code ...
end = perf_counter()
print(f"Elapsed: {end - start:.6f} seconds")
```

- `#4`:
```
from time import process_time

start = process_time()
# ... some code ...
end = process_time()
print(f"CPU Time: {end - start} seconds")
```

- `#5`:
```
from timeit import timeit

# first argument: stmt := statement => What shall be done?
# - can be a simple expression as well as a function / class method call
# number: How many times should be repeated a statement?

duration = timeit("sum(range(1000))", number=1000)
print(f"Time taken: {duration} seconds")
```

- `#6`:
```
from time import perf_counter_ns

start = perf_counter_ns()
# ... some code ...
end = perf_counter_ns()

print(f"Elapsed: {end - start} nanoseconds")
```

- `#7`:
```
from datetime import timedelta
from timeit import timeit

def bubble_sort():
    # code behind...

print(f"time amount: {timedelta(seconds=timeit(stmt=bubble_sort, number=1))}")
```

- `#8`:
```
from datetime import timedelta
from timeit import Timer

t = Timer(lambda: <function>(argument_0 [, argument_1, ..., argument_n-1]))
print(f"time amount: {timedelta(seconds=t.timeit(number=1))}")
```