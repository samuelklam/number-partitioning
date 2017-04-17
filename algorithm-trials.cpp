//
//  algorithm-trials.cpp
//  number-partition
//

#include "algorithm-trials.hpp"

void read_to_file(ofstream &file, string algo_name, int64_t residue, clock_t start_time, int num_iterations) {
    double end_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;
    file << residue << end_time << num_iterations << endl;
    cout << algo_name << "," << residue << "," << end_time << "," << num_iterations << endl;
}

void run_rand_algos(vector<int64_t> A, int num_iterations, ofstream *file_arr[7]) {
    clock_t start;
    
    // Karmarkar-Karp
    start = clock();
    read_to_file(*file_arr[0], "KK", karmarkar_karp(A), start, num_iterations);
    
    // Start with the same random solution for all 6 algorithms
    find_rand_solution(A);
    
    // Repeated Random
    start = clock();
    read_to_file(*file_arr[1], "Repeated-Random", repeated_random(A, num_iterations), start, num_iterations);
    
    // Hill Climbing
    start = clock();
    read_to_file(*file_arr[2], "Hill-Climbing", hill_climbing(A, num_iterations), start, num_iterations);
    
    // Simulated Annealing
    start = clock();
    read_to_file(*file_arr[3], "Simulated-Annealing", simulated_annealing(A, num_iterations), start, num_iterations);
    
    // Pre-Partioned Repeated Random
    
    // Pre-Partioned Hill Climbing
    
    // Pre-Partioned Simulated Annealing
}
