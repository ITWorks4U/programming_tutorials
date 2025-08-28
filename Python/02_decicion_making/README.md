#   Condition checks

-   allows you to compare one, two or more values to each other
-   everytime a condition check returns True a certain block of code(s) is able to execute

####    (very) important things

-   condition checks (also for loops, functions and classes) **must have** an *indentation* (white space **OR** tabs only)
-   do __NOT__ merge your python code with both intendentions, it's a syntax error
-   be careful, **which code** is a part of a condition check (also for a loop, a function or a class); means:
    -   every code, which is in the same indentation like the last code above, is *automatically* a part of this condition, loop, etc.
-   every special block of code (condition, loop, etc.) **must have** at least one code instruction or a multiline commentary
    -   it's a syntax error, if this field is empty, even a single commentary (**#**) as a dummy holder is in use
    -   if an implementation is in further use, then use the keyword: `pass`

-   note:
> it's not required, but for a better design and reading, mark your indentation at the end with an commentary, like: #end if, #end for, ...
>> those might be very useful for nested blocks

####	How to use condition checks wrong:
-   as mentioned before it's easy to use the wrong kind of condition checks, example:
    -   `a == b` means: *if the values of a and b are equal*

-   often wrongly interpreted:
    -   `a and b` means:    *if the values of a and b differs to zero*
    -   `a is b` means:     *if a and b refers to the identical memory address*
    -   `a & b` means:       *the binary expression (0, 1) of a and b are compared to each other and returns a new value*