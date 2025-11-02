#   I/O operations in C++

-   allows to read from a file or write any content into a file
>   **NOTE**:   You can also use C functions to operate with files, but this does not come without side effects.

##  library to use
-   `fstream`

| class | description | for what | additional informations |
| - | - | - | - |
| fstream | basic file stream class | can be used for reading, writing and for both directions | For reading: the file this file must exist and access rights must be set. For writing: If the file does not exist, then this will be created. By default the previous content will be overwritten. To append a new text, open the stream with `ios::app`. |
| ifstream | basic file input stream class | only for reading | the file must exist and access rights must be set |
| ofstream | basic file output stream class | only for writing | If the file does not exist, then this will be created. By default the previous content will be overwritten. To append a new text, open the stream with `ios::app`. |

### open a file stream
```
fstream fs;

// open a file stream for write into a file
fs.open("test.txt", ios_base::out);

// use ofstream instead
ofstream _os;
_os.open("test.txt");

// use ifsream instead
// this file MUST exist
ifstream _is;
_is.open("test.txt");
```
-   in contrast to the C variant `fopen()` no `FILE` pointer is in use
-   check, if the file has been opened: `fs.is_open()`

### close a file stream
-   use: `fs.close()`

>   **NOTE**:   In case of an error during runtime the file stream is not often going to close automatically, even this exception has been catched, e. g.: on an abnormal application termination. Make sure to close the file stream, no matter, if an exception has been thrown or not.

### handling with exceptions
```
// enable throwing on errors
fs.exceptions(ios::failbit | ios::badbit);
```
>   **NOTE**:   If you **omit** this command above, then in case of an **exception** this can **not** be caught!

### file modes

| mode | action | additional informations |
| - | - | - |
| `ios_base::in` / `ios::in` | read | Read a file, where this file **MUST** exist. Furthermore, you must have access rights to that file, it must not be a folder / directory, it must not be corrupted, ... |
| `ios_base::out` / `ios::out`  | write | write content to the file; this will overwrite the previous content |
| `ios_base::ate` / `ios::ate` | open at end  | opens a file stream and seek immediately to the end position |
| `ios_base::app` / `ios::app`  | appending| write content to the file; does not overwrite the previous content  |
| `ios_base::trunc` / `ios::trunc` | truncate, if existing | delete the content of a file, if this file exists |
| `ios_base::binary` / `ios::binary` | open in binary mode  | reading and writing must be combined with `ios::out` / `ios::in` |