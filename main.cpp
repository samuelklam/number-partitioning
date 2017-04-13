//
//  main.cpp
//  number-partition
//
//

#include <iostream>
#include "d-heap.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    DHeap t(10, 2);
    t.PrintHeap();
    t.Insert(23);
    t.PrintHeap();
    t.Insert(23);
    t.Insert(100);
    t.Insert(64);
    t.Insert(32);
    t.Insert(44);
    t.PrintHeap();
    for (int i = 0; i < 6; i++) {
        int64_t x = 0;
        x = t.DeleteMax(x);
        cout << x << endl;
    }
    t.PrintHeap();
}
