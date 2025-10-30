#   literals in C / C++
-   allows to define a specific data type, when the default assignment is not clear or not solid to use
    -   macro expressions (constant expressions)
    -   integers, floating point values

####    different types of literals

| literal | effect |
| - | - |
|  U          |  unsigned integer       |
|  L          |  long                   |
|  LU or UL   |  unsinged long          |
|  LL         |  long long              |
|  LLU or ULL |  unsigned long long     |
|  0B         |  binary expression      |
|  0          |  octal expression       |
|  0x         |  hexadecimal expression |
|  F          |  floating point         |
|  ' '        |  character literal      |
|  " "        |  string literal         |

####    typical pitfall
-   assuming, you're comparing a floating point value, like `float a = 1.0` with `1.0`
    -   not often is this equal, which should be
    -   by using a specigic literal, this may help out