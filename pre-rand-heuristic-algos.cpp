//
//  pre-rand-heuristic-algos.cpp
//  number-partition
//

#include "pre-rand-heuristic-algos.hpp"

vector<int64_t> get_rand_prepart(unsigned long A_size) {
    vector<int64_t> p(A_size);
    for(int i = 0; i < A_size; i++){
        p[i] = (rand() % A_size);
    }
    return p;
}

vector<int64_t> to_regular_solution(vector<int64_t> &A, vector<int64_t> &p) {
    vector<int64_t> new_A(A.size());
    for(int j = 0; j < A.size(); j++) {
        new_A[p[j]] += A[j];
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

int64_t repeated_random_prepart(vector<int64_t> A, vector<int64_t> P, int num_iterations) {
    vector<int64_t> A_new = to_regular_solution(A, P);
    int64_t residue = karmarkar_karp(A_new), new_residue;
    
    for (int i = 0; i < num_iterations; i++) {
        // try another random solution
        P = get_rand_prepart(A.size());
        A_new = to_regular_solution(A, P);
        new_residue = karmarkar_karp(A_new);
        if (new_residue < residue) {
            residue = new_residue;
        }
    }
    
    return residue;
}

int64_t hill_climbing_prepart(vector<int64_t> A, vector<int64_t> P, int num_iterations) {
    vector<int64_t> P2, A_new = to_regular_solution(A, P);
    int64_t residue = karmarkar_karp(A_new), new_residue;
    
    for(int i = 0; i < num_iterations; i++) {
        P2 = P;
        find_rand_neighbor_prepart(P2);
        A_new = to_regular_solution(A, P2);
        new_residue = karmarkar_karp(A_new);
        if (new_residue < residue) {
            P = P2;
            residue = new_residue;
        }
    }
    
    return residue;
}

int64_t simulated_annealing_prepart(vector<int64_t> A, vector<int64_t> P, int num_iterations) {
    vector<int64_t> A1, P1;
    A1 = to_regular_solution(A, P);
    int64_t residue = karmarkar_karp(A1), residue_A1;
    int64_t residue_best = residue;
    
    for(int i = 0; i < num_iterations; i++) {
        P1 = P;
        find_rand_neighbor_prepart(P1);
        A1 = to_regular_solution(A, P1);
        residue_A1 = karmarkar_karp(A1);
        
        if (residue_A1 < residue) {
            P = P1;
            residue = residue_A1;
        }
        else if (((double)rand() / (RAND_MAX)) <= exp((-(residue_A1 - residue)) / t_iter(i))) {
            P = P1;
            residue = residue_A1;
        }
        residue_best = min(residue, residue_best);
    }
    
    return residue_best;
}
