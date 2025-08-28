#   Accessing to a file for write and read
-   in both cases just use `open()` function
-   important things:
    -   by default a file is going to read
        -   this can be managed by the "mode" argument
        -   when you're using a stream (file stream, network stream, ...) **YOU** have to make sure to use the resource at the correct time, so it you don't longer need a resource **YOU** have to release this resource, otherwise it might result to undefined behaviors
    -   make sure **you're able** to access to your file to write to or read from
        -   if the file is corrupted, you don't have access to the file, it does not exist, ... an error on runtime will appear
    -   in case of an error your resource **IS NOT RELEASED** by default

### access settings
| mode | action | additional informations | creates a file | fails, if... |
| - | - | - | - | - |
| "r" | read | read a file, where this file **MUST** exist; furthermore, you must have access rights to that file, it must not be a folder / directory, it must not be corrupted, ... | no | insufficient permissions, file is a folder, does not exist, ...
| "w"  | write | write content to the file; this will overwrite the previous content | yes, if not existing | insufficient permissions, file is a folder, ...
| "w+" | write and read  | opens a file in both directions; "r+" and "a+" does the same action | see above | see above
| "a"  | appending | write content to the file; does not overwrite the previous content | yes, if not existing | see above
| "x" | create a new empty file | file must **not** exist | yes | the file already exists |
| "rb" | read byte form  | reading a file in a byte format correctly | no | insufficient permissions, file is a folder, ... |
| "wb" | write byte form | writing a file in a byte format correctly | yes, if not existing | insufficient permissions, file is a folder, ... |


### file operations (basic)
-   write to a file

```
fc = open(fileName, mode='w')

#   do operations here

fc.close()
```
-   read from a file

```
fc = open(fileName, mode='r')

#   do operations here

fc.close()
```

### file operations (the smarter way)
-   because you must ensure, that a resource needs to be released in any way, use `with` instead
-   when the block has been left in any case, the resource is going to release automatically
-   write to a file
```
with open(fileName, mode='w') as __alias_name__:
    #   do operations here
#end with
```

-   read from a file
```
with open(fileName, mode='r') as __alias_name__:
    #   do operations here
#end with
```