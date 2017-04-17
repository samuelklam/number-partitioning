//
//  algorithm-trials.hpp
//  number-partition
//

#ifndef algorithm_trials_hpp
#define algorithm_trials_hpp

#include <stdio.h>
#include <string>
#include <fstream>
#include "karmarkar-karp.hpp"
#include "rand-heuristic-algos.hpp"
#include "pre-rand-heuristic-algos.hpp"

using namespace std;

/*
 * Reads algorithm output to file
 * @param file : reference to file to read to
 * @param algo_name : name of the algorithm ran
 * @param residue : residue value calculated by the algo
 * @param start_time : starting time of the algo
 * @param num_iterations : # of iterations algo ran for
 */
void read_to_file(ofstream &file, string algo_name, int64_t residue, clock_t start_time, int num_iterations);

/*
 * Runs KK, repeated random, hill climbing, and annealing and the last 3 again but using
 * pre-partitioning. Prints / reads output to file as "Algo, Residual Value, Time Spent, Num Iterations"
 * @param A : sequence A
 * @param num_iterations : # of iterations to run each algo for
 * @param file_arr : reference to array containing file references to read output to
 */
void run_rand_algos(vector<int64_t> A, int num_iterations, ofstream *file_arr[7]);

#endif /* algorithm_trials_hpp */
