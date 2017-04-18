//
//  pre-rand-heuristic-algos.cpp
//  number-partition
//
#include "pre-rand-heuristic-algos.hpp"

vector<int64_t> get_rand_prepart(vector<int64_t> &A) {
    vector<int64_t> p;
    for(int i = 0; i < A.size(); i++){
        p.push_back(rand() % A.size());
    }
    return p;
}

vector<int64_t> to_regular_solution(vector<int64_t> &A, vector<int64_t> &p) {
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
    // start with random solution
    vector<int64_t> p = get_rand_prepart(A);
    vector<int64_t> A_copy = to_regular_solution(A, p);
    int64_t residue = karmarkar_karp(A_copy);
    int64_t new_residue;
    
    for (int i = 0; i < num_iterations; i++) {
        // try another new solution
        vector<int64_t> new_p = get_rand_prepart(A);
        A2 = to_regular_solution(A, new_p);
        new_residue = karmarkar_karp(A2);
        if (new_residue < residue) {
            A_copy = A2;
            residue = new_residue;
        }
    }
    return residue;
}

int64_t hill_climbing_prepart(vector<int64_t> A, int num_iterations) {
    vector<int64_t> A2;
    // start with random solution
    vector<int64_t> p = get_rand_prepart(A);
    vector<int64_t> A_copy = to_regular_solution(A, p);
    int64_t residue = karmarkar_karp(A_copy);
    
    for(int i = 0; i < num_iterations; i++) {
        find_rand_neighbor_prepart(p);
        vector<int64_t> A2 = to_regular_solution(A, p);
        int64_t new_residue = karmarkar_karp(A2);
        if(new_residue < residue) {
            A_copy = A2;
            residue = new_residue;
        }
    }
    
    return residue;
}

int64_t simulated_annealing_prepart(vector<int64_t> A, int num_iterations) {
    vector<int64_t> A2;
    // start with random solution A_rand
    vector<int64_t> p = get_rand_prepart(A);
    vector<int64_t> A_rand = to_regular_solution(A, p);
    A2 = A_rand;
    int64_t residue = karmarkar_karp(A_rand);
    int64_t residue_best = residue;
    
    for(int i = 0; i < num_iterations; i++) {
        // get random neighbour of A_rand
        find_rand_neighbor_prepart(p);
        vector<int64_t> A1 = to_regular_solution(A, p);
        int64_t residue_A1 = karmarkar_karp(A1);
        if (residue_A1 < residue) {
            A_rand = A1;
            residue = residue_A1;
        }
        else if (((double)rand() / (RAND_MAX)) <= exp((-(residue_A1 - residue)) / t_iter(i))) {
            A_rand= A1;
            residue = residue_A1;
        }
        residue_best = min(residue, residue_best);
    }
    return residue_best;
}
