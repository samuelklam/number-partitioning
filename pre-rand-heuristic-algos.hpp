//
//  pre-rand-heuristic-algos.hpp
//  number-partition
//

#ifndef pre_rand_heuristic_algos_hpp
#define pre_rand_heuristic_algos_hpp

#include <stdio.h>
#include <vector>
#include "karmarkar-karp.hpp"
#include "rand-heuristic-algos.hpp"
using namespace std;

/*
 * Generates a random solution
 */
vector<int64_t> get_rand_prepart(vector<int64_t> &A);

/*
 * Returns regular representation given pre partioning sequence p
 */
vector<int64_t> to_regular_solution(vector<int64_t> &A, vector<int64_t> &p);

/*
 * Mutates solution permutation p to a neighbouring solution permutation
 */
void find_rand_neighbor_prepart(vector<int64_t> &p);

/*
 * Runs pre-partitioned repeated random algorithm for num_iterations and returns final residual
 * @param A : starting random solution A (or S)
 * @param num_iterations : # of iterations to run for
 * @return : the final residual calculated
 */
int64_t repeated_random_prepart(vector<int64_t> A, int num_iterations);

/*
 * Runs pre-partitioned hill climbing algo for num_iterations and returns final residual
 * @param A : starting random solution A (or S)
 * @param num_iterations : # of iterations to run for
 * @return : the final residual calculated
 */
int64_t hill_climbing_prepart(vector<int64_t> A, int num_iterations);

/*
 * Runs pre-partitioned simulated annealing algorithm for num_iterations and returns final residual
 * @param A : starting random solution A (or S)
 * @param num_iterations : # of iterations to run for
 * @return : the final residual calculated
 */
int64_t simulated_annealing_prepart(vector<int64_t> A, int num_iterations);

#endif /* pre_rand_heuristic_algos_hpp */
