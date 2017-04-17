//
//  rand-heuristic-algos.cpp
//  number-partition
//

#include "rand-heuristic-algos.hpp"

int64_t compute_residue(vector<int64_t> &A) {
    int64_t sum = 0;
    unsigned long A_size = A.size();
    for (int i = 0; i < A_size; i++) {
        sum += A[i];
    }
    return abs(sum);
}

void find_rand_neighbor(vector<int64_t> &A) {
    unsigned long A_size = A.size();
    int idx1 = rand() % A_size;
    int idx2 = rand() % A_size;
    
    // ensure they are different
    while (idx1 == idx2) {
        idx2 = rand() % A_size;
    }
    
    A[idx1] = -A[idx1];
    if (rand() % 2) {
        A[idx2] = -A[idx2];
    }
}

void find_rand_solution(vector<int64_t> &A) {
    unsigned long A_size = A.size();
    for (int i = 0; i < A_size; i++) {
        if (rand() % 2) {
            A[i] = -A[i];
        }
    }
}

double t_iter(int64_t iter) {
    return pow(10000000000 * (0.8), floor(iter / double(300)));
}

int64_t repeated_random(vector<int64_t> A, int num_iterations) {
    vector<int64_t> A2;
    int64_t residue = compute_residue(A);
    int64_t new_residue;
    
    for (int i = 0; i < num_iterations; i++) {
        A2 = A;
        find_rand_solution(A2);
        new_residue = compute_residue(A2);
        if (new_residue < residue) {
            A = A2;
            residue = new_residue;
        }
    }
    
    return residue;
}

int64_t hill_climbing(vector<int64_t> A, int num_iterations) {
    vector<int64_t> A2;
    int64_t residue = compute_residue(A), new_residue;
    
    for (int i = 0; i < num_iterations; i++) {
        A2 = A;
        find_rand_neighbor(A2);
        new_residue = compute_residue(A2);
        if (new_residue < residue) {
            A = A2;
            residue = new_residue;
        }
    }
    
    return residue;
}

int64_t simulated_annealing(vector<int64_t> A, int num_iterations) {
    vector<int64_t> A1;
    int64_t residue = compute_residue(A), residue_A1;
    int64_t residue_best = residue;
    
    for (int i = 0; i < num_iterations; i++) {
        A1 = A;
        find_rand_neighbor(A1);
        residue_A1 = compute_residue(A1);
        
        if (residue_A1 < residue) {
            A = A1;
            residue = residue_A1;
        }
        else if (((double)rand() / (RAND_MAX)) <= exp((-(residue_A1 - residue)) / t_iter(i))) {
            A = A1;
            residue = residue_A1;
        }
        
        residue_best = min(residue, residue_best);
    }
    return residue_best;
}
