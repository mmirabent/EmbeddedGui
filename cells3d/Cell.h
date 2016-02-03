#ifndef MVM_CELL_H
#define MVM_CELL_H

class Cell {
    public:
        // Location struct
        struct Location {
            int x;
            int y;
            int z;
        } loc;

        // Array of three function pointers
        typedef void (*FuncPointer)(void);
        FuncPointer* functions;

        // Tick function
        void tick();

        // Constructor/destructor
        Cell();
        ~Cell();

};

#endif
