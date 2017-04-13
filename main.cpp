//
//  main.cpp
//  number-partition
//

#include <iostream>
#include <random>
#include "d-heap.hpp"
#include "karmarkar-karp.cpp"

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
int64_t RandomNumGenerator() {
    return dis(gen);
}

int main(int argc, const char * argv[]) {
    cout << RandomNumGenerator() <<endl;
}
