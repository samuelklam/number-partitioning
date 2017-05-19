# Number Partitioning

This repo implements a number of heuristics for solving the Number Partition Problem (NP-Complete). Repeated random, hill climbing, and simulated annealing are used on 1.) a randomized solution and 2.) a pre-partitioned solution. As input, the number partition problem takes a sequence A = (a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub>) of non-negative integers. The output is a sequence S = (s<sub>1</sub>, s<sub>2</sub>, ..., s<sub>n</sub>) of signs s<sub>i</sub> in {-1, +1} such that the residue (the absolute value of their sum) is minimized.

The first is a standard representation of a solution, which is simply as a sequence S of +1 and -1 values. A random solution can be obtained by generating a random sequence of n such values. An alternative way to represent a solution called pre-partitioning is as follows. We represent a solution by a sequence P = {p<sub>1</sub>, p<sub>2</sub>, ..., p<sub>n</sub>} where p<sub>i</sub> in {1, ..., n}. The sequence P represents a pre-partitioning of the elements of A, in the following way: if p<sub>i</sub> = p<sub>j</sub>, then we enforce the restriction that a<sub>i</sub> and a<sub>j</sub> have the same sign. Equivalently, if p<sub>i</sub> = p<sub>j</sub>, then a<sub>i</sub> and a<sub>j</sub> both lie in the same subset, either A<sub>1</sub> or A<sub>2</sub>.

For a full writeup refer to: `number-partitioning-writeup.pdf`.

## Usage
```
$ make
$ ./kk inputfile
```
`inputfile` is a list of unsorted integers (100 integers is standard), one per line, and the output is the residue obtained by running Karmarkar-Karp with these 100 numbers as input. To run the heuristic algorithms, change `algo_flag` in `main.cpp` to a non-zero value.
