
# Calling superclass constructors

Calling a superclass' constructor from a subclass constructor

Imagine ou have a class R1 that inherits from Cell. The R1 constructor is
defined as such

    R1(int p, int q, int r):Cell(q) {
        // Stuff
    }

In this case, the constructor for Cell is called, and provided with the value q.
The value q can also be a number, a function call, whatever.

