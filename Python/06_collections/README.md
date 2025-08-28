#   Collections in Python

-   allows you to handle a bunch of objects at the same time
-   unlike to compiler languages, like C, C++, Java, C#, ... you can store **anything** in your collection

### different types of collections

| collection | effect | can be modified | defined with | example |
| - | - | - | - | - |
| list | linear, unordered collection of multiple elements | yes |  `list(), []` | `[1,2,3,4,5]`| 
| tuple	| unordered collection of fixed elements | no | `tuple(), ()` | `(1,2,3,4,5)`
| set | linear, ordered collection of unique elements | yes | `set()` | `{1,2,3,4,5}` |
| dictionary | ordered collection of key-value-pairs, where the keys are ordered by default; the key is unique | yes |`dict(), {}` | `{a: 1, b: 2, c: 3}`

> Are you confused about a set and dictionary? While a set contains `{any elements here}`, the brackets `{}` defaults to a dictionary.
>> Because there are no other bracket types left, which could determine them.

######  hint:
-   Python doesn't comes with an array, where `[]` also does not stands for an array