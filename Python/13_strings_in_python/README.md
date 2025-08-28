#   strings are just words, right?

-   acutally yes, but sometimes it shouldn't
    -   especially when reading from keyboard or from a file a "word" shall be a number
        -   this is often be supposed to convert to a correct format
-   strings are immutable
    -   once defined it's not allowed to change it's content on the hardcoded way
    -   there're functions, which can do this, but these can only return a new string with the new content
    -   the old content still exists on runtime

##  A word is easy to read in every situation, right?

-   No.
-   It depends on the used format.
-   Usually, you're using __ASCII__ (basic alphabet in small and capital letters, numbers between 0-9 and "only" a few of "special characters").
-   Imagine, you want to use emojis, then you have to use an another unicode format.
-   The same condition exists for other real languages, like chinese, russian, ...

### examples:
-   strings are immutable
    -   in C/C++ this works with **C-Strings** only, but with regular **strings** this is not possible
    -   strings, however, are similar to a list and allows you also to access to the subset of characters

```
word = "This is a simple text. 123,456,789, blah blah blah, ..."

# won't work...
# word[4] = 'f'
# print(word)
# del word[3]
# print(word)
```

-   working with unicodes...
```
#print a bee
print('\U0001f41d')

#...or a ladybug
print('\U0001f41e')

#...or a fish
print('\U0001f41f')

#...or a traffic light
print('\U0001F6A6')

#...make a hand wave instead
print("\U0001F590")

#...using a specific expression (starting with \N) and try to figure out,
#if these might work
print('\N{MAHJONG TILE RED DRAGON}')
print('\N{MAHJONG TILE GREEN DRAGON}')

#these are identical:
print('\N{GREEK CAPITAL LETTER DELTA}')
print('\U00000394')

#...also these
print('Ê')
print('\N{LATIN CAPITAL LETTER e}\N{COMBINING CIRCUMFLEX ACCENT}')
```