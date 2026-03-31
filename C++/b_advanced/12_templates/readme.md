#   Templates in C++
-   are in use for a general class shape, which may cover different data types
    -   imagine, you're creating a bottle class
        -   this can be used to fill water, as well as, color
    -   ...
-   unlike to write a function / class / class method for type t0, t1, t2, ... over and over again

##  define a template
-   there're two ways to realize this:
    -   `template <class T>`
    -   `template <typename T>`
        -   is also a valid way for a template definition
    -   `"T"` is often given for any "type"
        -   this can also be anything else
-   a template can be covered for a function / class method, as well as, for a whole class

```
template <class T>
T getMaximum(T a, T b) {
    return a > b ? a : b;
}

template <typename anything>
void doSomething(anything a) {
    cout << a << endl;
}

int main() {
    int a = 10;
    int b = 15;

    double c = 3.141;
    double d = 4e12;

    cout << "a (" << a << ") or b (" << b << "): " << getMaximum<int>(a, b) << endl;
    cout << "c (" << c << ") or d (" << d << "): " << getMaximum(c, d) << endl;
    cout << "c (" << c << ") or d (" << d << "): " << getMaximum<double>(c, d) << endl;

    doSomething(a);
    doSomething(b);
    doSomething(c);
    doSomething(d);
    doSomething("abcdef");

    return 0;
}
```

##  template class example
```
class MathError : public exception {
    string error_message;

    public:
    MathError(string error_message) {
        this->error_message = error_message;
    }

    virtual ~MathError() {}

    string get_message() const {
        return this->error_message;
    }
};

template <class T>
class Calculator {
    public:
        Calculator() {}
        virtual ~Calculator() {}

        T add(T a, T b) const {
            return a + b;
        }

        T sub(T a, T b) const {
            return a - b;
        }

        T mul(T a, T b) const {
            return a * b;
        }

        T div(T a, T b) const {
            if (b == 0) {
                throw MathError("b must not be 0");
            }

            return a / b;
        }
};

int main() {
    int a = 10;
    int b = 5;

    double c = 1.52;
    double d = 4e-2;

    cout << "-------------" << endl;

    Calculator<int> cInt;
    cout << "a + b = " << cInt.add(a, b) << endl;
    cout << "a - b = " << cInt.sub(a, b) << endl;
    cout << "a * b = " << cInt.mul(a, b) << endl;
    cout << "a / b = " << cInt.div(a, b) << endl;

    cout << "-------------" << endl;

    Calculator<double> cDouble;
    cout << "c + d = " << cDouble.add(c, d) << endl;
    cout << "c - d = " << cDouble.sub(c, d) << endl;
    cout << "c * d = " << cDouble.mul(c, d) << endl;
    cout << "c / d = " << cDouble.div(c, d) << endl;

    return 0;
}
```