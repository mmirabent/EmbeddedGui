
# Calling superclass constructors

Calling a superclass' constructor from a subclass constructor

Imagine ou have a class R1 that inherits from Cell. The R1 constructor is
defined as such

    R1(int p, int q, int r):Cell(q) {
        // Stuff
    }

In this case, the constructor for Cell is called, and provided with the value q.
The value q can also be a number, a function call, whatever.

# Static members

Static variables inside a class are global variables

    class Cell
    {
        int a;
        static int b;
    }

    Cell x = new Cell();
    Cell y = new Cell();

x has one variable, a. Y also has one variable, a. Because b belongs to the
class.

In the assignment, do this

    class Cell {
        private:
        static void f1(void){...}
        static void f2(void){...}
        static void f3(void){...}

And set the funtion pointer array to these functions

Static functions inside a class are the same way. They exist outside of any
objects. Therefore, the static functions are available before any objects are
instantiated. Also, because static functions aren't part of any instantiated
objects, they cannot access instance variables of the object.


