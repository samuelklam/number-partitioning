//
//  main.cpp
//  number-partition
//

#include <iostream>
#include <random>
#include <fstream>
#include <vector>
#include "d-heap.hpp"
#include "karmarkar-karp.hpp"
#include "rand-heuristic-algos.hpp"

using namespace std;

// Max value is 10^12
#define MAX_VAL 1000000000000

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int64_t> dis(1, MAX_VAL);

/*
 * Generates a random # from [1, 10^12]
 * @return : the randomly generated #
 */
int64_t random_num_generator() {
    return dis(gen);
}

/*
 * Function initializes sequence A with values from input file or randomly
 * @param b : if 1 read values from input file else generate random numbers
 * @param n : # of values to read in / generate
 * @param arr : reference to array to store values in
 * @param infile : reference to file to read input from
 */
void initialize_sequence(bool b, int n, vector<int64_t> &A, ifstream &infile) {
    if (b) {
        int64_t val;
        for (int i = 0; i < n; i++) {
            infile >> val;
            A[i] = val;
        }
    }
    else {
        for (int j = 0; j < n; j++) {
            A[j] = random_num_generator();
        }
    }
}

int main(int argc, const char * argv[]) {
    if (argc != 2) {
        cout << "Invalid # of arguments!" << endl;
        return 1;
    }
    
    ifstream infile(argv[1]);
    int algo_flag = 1, num_elements = 100, num_instances = 1, num_iterations = 25000;
    vector<int64_t> A(num_elements);
    
    // read in values from input file and run KK
    if (algo_flag == 0) {
        initialize_sequence(1, num_elements, A, infile);
        cout << karmarkar_karp(A) << "\n" << endl;
    }
    
    // run regular randomized heuristic algos
    else if (algo_flag == 1) {
        srand((unsigned)time(NULL));
        for (int i = 0; i < num_instances; i++) {
            initialize_sequence(0, num_elements, A, infile);
            run_rand_algos(A, num_iterations);
        }
    }
    
    // run pre-partition randomized heuristic algos
    else {
        cout << "TODO";
    }
    
    return 0;
}
