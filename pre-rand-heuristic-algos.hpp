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
 * Uses a pre-partitioning sequence to generate corresponding permutation of A
 */
vector<int64_t> get_rand_prepart(vector<int64_t> &A);

/*
 * Mutates solution permutation p to a neighbouring solution permutation
 */
void find_rand_neighbor_prepart(vector<int64_t> &p);

/*
 * Runs pre partioned repeated random algorithm for num_iterations and returns final residual
 * @param A : starting random solution A (or S)
 * @param num_iterations : # of iterations to run for
 * @return : the final residual calculated
 */
int64_t repeated_random_prepart(vector<int64_t> A, int num_iterations);

#endif /* pre_rand_heuristic_algos_hpp */
