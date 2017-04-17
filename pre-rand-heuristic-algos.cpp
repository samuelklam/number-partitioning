//
//  pre-rand-heuristic-algos.cpp
//  number-partition
//
#include "pre-rand-heuristic-algos.hpp"

vector<int64_t> get_rand_prepartioning(vector<int64_t> &A) {
    vector<int64_t> p;
    for(int i = 0; i < A.size(); i++){
        p.push_back(rand() % A.size());
    }
                    
    vector<int64_t> new_A (A.size(), 0);
    for(int j = 0; j < A.size(); j++) {
        new_A[p[j]] = new_A[p[j]] + A[j];
    }
    return new_A;
}

void find_rand_neighbor_prepart(vector<int64_t> &p) {
    int idx1 = rand() % p.size();
    int idx2 = rand() % p.size();
    
    // ensure p[idx1] != idx2
    while (p[idx1] == idx2) {
        idx2 = rand() % p.size();
    }
    p[idx1] = idx2;
}

int64_t repeated_random_prepart(vector<int64_t> A, int num_iterations) {
    vector<int64_t> A2;
    int64_t residue = karmarkar_karp(A);
    int64_t new_residue;
    
    for (int i = 0; i < num_iterations; i++) {
        A2 = get_rand_prepartioning(A);
        new_residue = karmarkar_karp(A2);
        if (new_residue < residue) {
            A = A2;
            residue = new_residue;
        }
    }
    return residue;
}


