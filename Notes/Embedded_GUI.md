# Quiz 1 Answers

1. 2D array of functions

    void (* array[3][5](int,int)); // Declaring the functin pointer array

    for (int i = 0; i < 3; i++) {
	    for(int j = 0; j < 5; j++) {
		    x[i][j] = pix;
	    }
    }

2. Show activation record for '''start sam 1 2'''

| name | stack                  |
| :--- | :--------------------- |
| c    | 2                      |
| b    | 1                      |
|      | return address to main |
| A    | 2                      |
| y    | 0                      |
| x    | 4                      |
|      | Return address to os   |
| argv | pointer to "2"         |
| argv | pointer to "1"         |
| argv | pointer to "sam"       |
| argv | pointer to "start"     |
| argc | 4                      |

# Class Scope

Scope example

    int count = 0; // Global variable
    main () {
	    int count = 0; // local variable
	    count = 4;     // the count defined closest in scope to us
	    ::count = 10;  // The global one
    }

Another one

    class X {
        public:
            static int count;
            //
            // ...
            //
    }

    int X::count = 0; // Initialize

    main ()
    {
        int x = 0;
        cout << X::count << endl // to access count in class X, use ::
    }

    main()
    {
        for(int i = 0; i < 10; i++) {
            foo()
        }
    }

    foo() {
        int a = 0;
        static int b = 0;

        a++;
        b++;

        cout << a << b << endl;
    }

The last main program will output 11,12,13,14,15,16, etc... Because a is not
static, it gets reset every time the function is run. Because b is static, it
retains its value upon subsequent calls to foo. b is a global variable with
local access

# extern variables

File 1(main.c)

    extern int x;

    main() {
        x = 2; // Without the extern keyword, this is an error
    }

File 2(mod.c)

    int x;

    foo() {
        // stuff
    }

Compiler:

main.c -> main.o
mod.c -> mod.o

The extern keyword says, "Trust me, this variable exists somewhere outside the
code." The linker has to find x and add the address at link time.

File 2(mod.c) broken edition

    static int x; // Static makes x unavailable outside this compilation unit

    foo() {
        // stuff
    }

Now, the linker can't add the "fixup" to the file, so main.o can't access x

# References and pointers

Example 1

    int x = 5;
    int y = 6;
    int *p;
    p = &x;
    p = &y;
    *p = 10;
    assert(x==5)  // true
    assert(y==10) // true

Example 2

    int x = 0;
    int &r = x; // r is an alias, annother name for an existing variable
                // r and x ARE the same variable. R is not a pointer to x
                // it IS x
    int *p = &x;
    int *p2 = &r;
    assert(p==p2); // true

Example 3

    int x = 0;
    int y = 0;
    int *p = &x;
    int *q = &y;
    int **pp = &p;
    pp = &q;
    **p = 4;
    assert(y==4) // true
    assert(x==0) // true

# Abstract classes

Example

    // Abstract class
    class Point { 
        int x,y;
        static int cnt;

        // some member functions
    public:
        void setX(int a){ x=a };
        void setY(int a){ y=a };
        void move(int a, int b){};  
        void move(int p) = 0;         // pure virtual function
    }

    // Concrete class
    class Circle {
        void move(int p) {
            // stuff
        }
    }

Because we defined move(int) in the Circle class, it's not abstract. We can't
instantiate abstract classes. Since Point has a pure virtual function, we can't
instantiate an object of type Point, but we can instantiate an object of type
Circle.

# Polymorphism

Example

    p = new Point(); // pretend Point is concrete
    p = new Circle();

    p->x(); // Calls circle's point function

Polymirphism allows you to create a pointer to a base class and assign an
instance of a child class to that pointer. When you call member functions of
the base class, the overloaded function of the child will be called if it
exists. If it doesnt' exist, the base class's function will exist. With this we
can guarantee that a function will exist.

# Development Environment

* Ubuntu
* Codeblocks(IDE)
* wxWidgets

## INstructions for ubuntu

    # In a terminal
    sudo apt-get update
    sudo apt-get install gcc g++    # Installs C and C++ compiler

