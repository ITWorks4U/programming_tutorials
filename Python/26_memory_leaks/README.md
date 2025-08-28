#   Memory leaks
-   Python has usually the **garbage collector** to clean up no more used references by default, however, you can also create memory leaks to (horrible) slow down your python application

###  What is a memory leak?

-   a requested resource, like file operation, network access, ..., which has not (successfully) been released
-   often accoured by using a resouce without `with`, if available and in combination with:
    -   an exception
    -   a signal
    -   "the normal way" without releasing that memory
-   without caring about your application or also your **whole machine** can also be affected

### How to figure out memory leaks
-   tracemalloc
-   gc
-   memory_profiler
-   guppy3
-   psutil
-   ...

####    memory leak examples:
-   file streams without releasing the resource
```
fc = open("file.txt", mode="w")
# some file I/O operations here

# forget to close the file stream by fc.close()
```
>   This resource has not been released.

-   file streams with exception
```
fc = open("file.dat", mode="w")
# some I/O operations here
raise Exception("Oops!")
fc.close()
```
>   A resource release exists, but in case of an exception this resource is now leaked.

-   grow a collection, like a list without clear the previous content
```
leaky_list: list = []

def leaky_func():
    big_data = "X" * 10**6  # 1 MB
    leaky_list.append(big_data)

for _ in range(100000):
    leaky_func()
```