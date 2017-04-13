//
//  rand-heuristic-algos.cpp
//  number-partition
//

#include "rand-heuristic-algos.hpp"

int64_t compute_residue(vector<int64_t> &A) {
    int64_t sum = 0;
    for (int i = 0; i < A.size(); i++) {
        sum += A[i];
    }
    return abs(sum);
}

void print_A(vector<int64_t> &A) {
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << ",";
    }
    cout << endl;
}

void find_rand_neighbor(vector<int64_t> &A) {
    int idx1 = rand() % A.size();
    int idx2 = rand() % A.size();
    
    // ensure they are different
    while (idx1 == idx2) {
        idx2 = rand() % A.size() + 1;
    }
    
    A[idx1] = -A[idx1];
    if (rand() % 2) {
        A[idx2] = -A[idx2];
    }
}

void find_rand_solution(vector<int64_t> &A) {
    for (int i = 0; i < A.size(); i++) {
        if (rand() % 2) {
            A[i] = -A[i];
        }
    }
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
    int64_t residue = compute_residue(A);
    int64_t new_residue;
    
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

void run_rand_algos(vector<int64_t> A, int num_iterations) {
    clock_t start;
    cout << "Algorithm,Residual Value,Time,Num Iterations" << endl;
    start = clock();
    
    // Karmarkar-Karp
    cout << "Karmarkar-Karp," << karmarkar_karp(A) << "," << (double)(clock() - start) / CLOCKS_PER_SEC << "," << num_iterations << endl;
    
    // Start with the same random solution for all 3 algorithms
    find_rand_solution(A);
    
    // Repeated Random
    start = clock();
    cout << "Repeated-Random," << repeated_random(A, num_iterations) << "," << (double)(clock() - start) / CLOCKS_PER_SEC << "," << num_iterations << endl;
    
    // Hill Climbing
    start = clock();
    cout << "Hill-Climbing," << hill_climbing(A, num_iterations) << "," << (double)(clock() - start) / CLOCKS_PER_SEC << "," << num_iterations << endl;
    
    // Simulated Annealing
    // TODO
}
