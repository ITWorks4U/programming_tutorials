#   Assembly instructions
-   can be used to speed up any instructions exremely fast, because the commands can be written into the CPU's understanding language
    -   depending on which operating system(**OS**), C version, CPU techology, bit technology, ... it's often hard to write an instruction for the raw CPU

-   compile the application with `-S` flag to see, how your application may looks like in assembly language, so your CPU is able to understand those instructions

#####   additional compiler flags

| flag | meaning |
| - | - |
| `-O` | remove optimizing => reduces your assembly instructions |
| `-fverbose-asm` | forces to add useful commands for the assembly file as comments |

####    some assembly instructions
-   depending on CPU, C-compiler, enviroment, ...
-   `asm {}`, `__asm {}`, `__asm__ {}`, `asm ();`, ... => depends on your used C compiler


#####   for a Intel x8086 CPU
```
int a = 10;
int b = 15;
int c = 0;

//  1)  move "a" to AX register (AX = 16 bit register | AH, AL = 8 bit register)
//  2)  move "b" to BX register
//  3)  add to AX the content of BX
//  4)  move to "c" the result from AX

__asm__ {
    mov ax, a
    mov bx, b
    add ax, bx
    mov c, ax
};

printf("a (%d) + b (%d) = %d\n", a, b, c);
```

#####   often in use for modern CPU
```
int a = 10;
int b = 15;
int c = 0;

asm volatile ("addl %%ebx, %%eax;"
    //	define an output to store a result to a certain variable
    //	hint: on any IDE / OS it may happen, that you see an error here
    : "=a" (c)

    //	define inputs to store to EBX and EAX
    : "a" (a), "b" (b)
);

printf("a (%d) + b (%d) = %d\n", a, b, c);
```