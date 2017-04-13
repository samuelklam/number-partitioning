//
//  karmarkar-karp.hpp
//  number-partition
//

#ifndef karmarkar_karp_hpp
#define karmarkar_karp_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include "d-heap.hpp"

using namespace std;

/*
 * Function calculates residue value from a sequence S using Karmarkar Karp algo
 * @param S : reference to sequence of values
 * @return : residue value
 */
int64_t karmarkar_karp(vector<int64_t> &S);

#endif /* karmarkar_karp_hpp */
