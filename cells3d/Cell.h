#ifndef MVM_CELL_H
#define MVM_CELL_H

class Cell {
  private:
    static void f1(void);
    static void f2(void);
    static void f3(void);

    // Location struct
    struct Location {
        int x;
        int y;
        int z;
    } loc;

    // Array of three function pointers
    typedef void (*FuncPointer)(void);
    FuncPointer *functions;

  public:
    // Tick function
    void tick();

    // Constructor/destructor
    Cell();
    Cell(int x, int y, int z);
    ~Cell();
};

#endif /* Cell.h */
