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
void initialize_sequence(bool b, int n, vector<int64_t> &S, ifstream &infile) {
    if (b) {
        int64_t val;
        for (int i = 0; i < n; i++) {
            infile >> val;
            S[i] = val;
        }
    }
    else {
        for (int j = 0; j < n; j++) {
            S[j] = random_num_generator();
        }
    }
}

int main(int argc, const char * argv[]) {
    if (argc != 2) {
        cout << "Invalid # of arguments!" << endl;
        return 1;
    }
    
    ifstream infile(argv[1]);
    bool input_bool = 1;
    int num_elements = 10;
    vector<int64_t> S(num_elements);
    
    // read in values from input file
    if (input_bool) {
        initialize_sequence(input_bool, num_elements, S, infile);
        cout << karmarkar_karp(S) << endl;
    }    
}
