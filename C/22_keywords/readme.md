#   keywords in C
-   allows you to use specific cases, like internal variables, functions and many more:
    -   auto
    -   static
    -   extern
    -   register
    -   volatile
    -   restrict

| keyword | description | purpose |
| - | - | - |
| auto | backward compability to older languages, like `B` | in C it became obsolete and has no more purpose |
| static | storage class modifier; it has different meanings depending on where to use | often used for internal global variables and functions |
| extern | declare a variable in a C-header file to allow to use this value everywhere | without declaring a variable with `extern` an application can't be build |
| register | store a variable into the CPU register instead of the "slow" RAM, but it depends on the compiler itself, if this is possible | when a variable shall be used very often, which shall not be stored into the RAM |
| volatile | a "promise" for the C-compiler, when on runtime a variable's value may be changed by an event | in use for: `memory mapped peripheral registers`, `global variables modified by an interrupt service routine`, `global variables accessed by multiple tasks within a multi-threaded application` |
| restrict | a "promise" for the C-compiler, that a clean code is provided to speed up the application; only exists in C | speeding up the code, when this is possible, otherwise the application may crash |