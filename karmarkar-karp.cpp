//
//  karmarkar-karp.cpp
//  number-partition
//

#include "karmarkar-karp.hpp"

int64_t karmarkar_karp(vector<int64_t> &S) {
    
    int s_size = (int)S.size();
    int64_t diff = 0;
    int64_t n1;
    int64_t n2;
    
    // error check if there is only 1 value for S
    if (s_size <= 1) {
        return S[0];
    }
    
    // initialize Binary max-heap
    DHeap max_heap(s_size, 2);
    
    for (int i = 0; i < s_size; i++) {
        max_heap.Insert(S[i]);
    }
    
    for (int j = 0; j < s_size - 1; j++) {
        max_heap.DeleteMax(n1);
        max_heap.DeleteMax(n2);
        diff = abs(n1 - n2);
        max_heap.Insert(diff);
    }
    
    return diff;
}
