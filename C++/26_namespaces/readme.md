#	Namespaces

-   allows you to capsule classes, functions, attributes, ... into an own space to use
-   you can also define identical classes, which can be stored into several namespaces without triggering an error, unless, you'll allow this

### define a namespace

-   you can also define namespace(s) within a namespace, like:
```
namespace any_name_here {
    /*
    * looks similar to a data structure, whereas
    * the namespace area don't need a semicolon at the end
    */
}

// using the certain namespace #1
using namespace any_name_here;

// using the certain namespace #2
any_name_here::<access to whatever you want>

// .......

namespace <name_1> {
    namespace <name_1_1> {
        namespace <name_2> {
            .......
        }
    }

    namespace <name_1_2> {
        ....
    }
}
```

-   in contrast to the other data structures, a namespace doesn't need a semicolon: **;** at the end
-   a namespace can also be extended in any other header / source file