# ---
# run a sequence without using threads, like:
# "Sort 50,000 random numbers with bubble sort, because why not?""
#
# In contrast to C/C++ programming, which takes only few
# minutes, depending on the used system, in Python this
# is a really, really, ... REALLY bad idea.
# ---

from datetime import timedelta
from timeit import timeit

import bubble_sort.bubble_sort as bs

print(f"start to sort {bs.MAX_NUMBERS} elements twice in a row with bubble sort: ", end="")
print(f"time amount: {timedelta(seconds=timeit(stmt=bs.bubble_sort, number=2))}")