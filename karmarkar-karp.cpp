//
//  karmarkar-karp.cpp
//  number-partition
//

#include "karmarkar-karp.hpp"

int64_t karmarkar_karp(vector<int64_t> &A) {
    
    int a_size = (int)A.size();
    int64_t diff = 0;
    int64_t n1;
    int64_t n2;
    
    // error check if there is only 1 value for S
    if (a_size <= 1) {
        return A[0];
    }
    
    // initialize Binary max-heap
    DHeap max_heap(a_size, 2);
    
    for (int i = 0; i < a_size; i++) {
        max_heap.Insert(A[i]);
    }
    
    for (int j = 0; j < a_size - 1; j++) {
        max_heap.DeleteMax(n1);
        max_heap.DeleteMax(n2);
        diff = abs(n1 - n2);
        max_heap.Insert(diff);
    }
    
    return diff;
}

void gen_rand_solution(vector<int64_t> &S) {
    for (int i = 0; i < S.size(); i++) {
        bool sign = rand() % 2;
        if (sign) {
            
        }
    }
}
