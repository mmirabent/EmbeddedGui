# Is-A vs Has-A

Is a is inheritance.

A <- B

B Is an A

If B inherits from A, B is an A.

Has is composition, this happens when B has a reference to A or contains A
within it. B owns an object of type A.

When you use composition, you must have a delete method, to release members. If
not, you might delete the object that owns another object, but not the owned
object. This will cause a memory leak.

# Websites

[wxWidgets 2.8 docs](http://docs.wxwidgets.org/2.8/). You probably want class by
category

# Pointers (again) ((yay))

Pointer double indirection example

    int x = 0;
    int y = 0;
    int *p = &x;
    int *q = &y;
    int **pp = &p;
    pp = &q;
    **pp = 4;

    assert(y==4); // True

Another one

    int x = 0;
    int &r = x;
    int *p = &x;
    int *p2 = &r;

    assert(p==p2); // True

"The easy one"

Write a program with inputs x and y
Create a 2D array with x rows and y columns
Fill the array with random numbers from 1 to 100
Print out the array
Ask if the user wants another array

HINT: 2D Array will look like this

    int **myArray;

Don't forget to delete the array

Due next tuesday

