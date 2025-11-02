#   object oriented programming (OOP)
-   allows you to define container structures as classes to handle a bunch of informations as once
    -   similar to `struct` (see: [chapter 19 for C++](https://github.com/ITWorks4U/programming_tutorials/tree/main/C%2B%2B/19_structures))
-   comes with the `class` keyword
    -   classes are similar to a struct, but comes with more and secured features
    -   comes with expressions, like `public`, `private` or `protected`
        -   by default everything is private

### define a class
```
class Point {
    // anything what you want here
    // by default everything is private, like:
    double x;
    double y;

    public:
    Point() {}                  //  constructor
    ~ Point() {}                //  destructor

    // ...
};
```
>   **NOTE**:   In contrast to other OOP languages, a class in C++ *should* contain a (virtual) destructor, especially for inheritance and polymorphism, otherwise an undefined behavior will appear.

### inheritance
-   allows to extend a given class with new implementations without changing the original class

>   **NOTE**:   If the base class has been changed, then this **also** affects the child classes!
```
// the super class
class GeometricObject {
    // ...
};

// the child classes
class Triangle : public GeometricObject {
    // ...
}

class Rectangle : public GeometricObject {
    // ...
}
```

### polymorphism
-   allows to use the super class to work with the child classes
    -   works only, if the used class is the real super class
    -   comes with some nasty side effects

```
GeometricObject *go = new Circle();

// do something here

// MUST be released
delete go;
```