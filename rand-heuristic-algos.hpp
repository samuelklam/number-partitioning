//
//  rand-heuristic-algos.hpp
//  number-partition
//

#ifndef rand_heuristic_algos_hpp
#define rand_heuristic_algos_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include "karmarkar-karp.hpp"

using namespace std;

/*
 * Computes the residual given a sequence, A, of values
 * @return : the residual
 */
int64_t compute_residue(vector<int64_t> &A);

/*
 * Prints the sequence A for debugging purposes
 */
void print_A(vector<int64_t> &A);

/*
 * Mutates A to a random neighbor
 */
void find_rand_neighbor(vector<int64_t> &A);

/*
 * Mutates A to a random solution
 */
void find_rand_solution(vector<int64_t> &A);

/*
 * Mutates A to a random solution and returns it
 */
vector<int64_t> return_rand_solution(vector<int64_t> &A);

/*
 * Iterator function for use in calculating probability in simulated annealing
 */
double t_iter(int64_t iter);

/*
 * Runs repeated random algorithm for num_iterations and returns final residual
 * @param A : starting random solution A (or S)
 * @param num_iterations : # of iterations to run for
 * @return : the final residual calculated
 */
int64_t repeated_random(vector<int64_t> A, int num_iterations);

/*
 * Runs hill climbing algo for num_iterations and returns final residual
 * @param A : starting random solution A (or S)
 * @param num_iterations : # of iterations to run for
 * @return : the final residual calculated
 */
int64_t hill_climbing(vector<int64_t> A, int num_iterations);

/*
 * Runs simulated annealing algorithm for num_iterations and returns final residual
 * @param A : starting random solution A (or S)
 * @param num_iterations : # of iterations to run for
 * @return : the final residual calculated
 */
int64_t simulated_annealing(vector<int64_t> A, int num_iterations);

/*
 * Runs KK, repeated random, hill climbing, and annealing. Prints / reads
 * output to file as "Algo, Residual Value, Time Spent, Num Iterations"
 * @param A : sequence A
 * @param num_iterations : # of iterations to run each algo for
 */
void run_rand_algos(vector<int64_t> A, int num_iterations);

#endif /* rand_heuristic_algos_hpp */
