#   bit operations
-   allows to convert data or values into a certain format
    -   bit operations, like bit-and, bit-or, bit-xor, ...
    -   bit shifting
-   since bit operations are faster than arithmetical operations, this can be used in many situations, however, it might be a bit complicated to use

>   **NOTE**:   Don't mix logical operations with bit operations, like logic-and and bit-and. These are quite different.

>   **NOTE**:   In modern languages, C will also be handled as a "modern language", **logic-and** is written as **A && B**, whereas **bit-and** is written as **A & B**. 

##  1)  bit operations in detail
### bit and
-   combine the value A and value B bit by bit and return a result
-   the result is for bit i (i = 0,1,2,...) is 1 only, if A(i) and B(i) are 1

| A | B | A & B |
| - | - | - |
| 0 | 0 | 0 |
| 1 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 1 | 1 |

### bit or
-   combine the value A and value B bit by bit and return a result
-   the result is for bit i (i = 0,1,2,...) is 1 only, if A(i) or B(i) or both are 1

| A | B | A & B |
| - | - | - |
| 0 | 0 | 0 |
| 1 | 0 | 1 |
| 0 | 1 | 1 |
| 1 | 1 | 1 |

### bit xor
-   combine the value A and value B bit by bit and return a result
-   the result is for bit i (i = 0,1,2,...) is 1 only, if A(i) and B(i) are different

| A | B | A & B |
| - | - | - |
| 0 | 0 | 0 |
| 1 | 0 | 1 |
| 0 | 1 | 1 |
| 1 | 1 | 0 |

### inverted
-   invert bit i (i = 0,1,2,...)
-   if A(i) = 1, then ~A(i) = 0

| A | ~A 
| - | - |
| 0 | 1 |
| 1 | 0 |

##  2)  bit shifting
-   allows to shift a number by n bits to the left or right
-   to left: the number gets higher and the remaining "free" spaces right will be filled with 0
-   to right: the number gets lower to 0 and the remaining "free" spaces left will be filled with 0
-   in summary, you won't toggle a positive number into a negative number until the numeric over- or underflow has been exceeded