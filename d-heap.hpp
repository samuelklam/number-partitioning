//
//  d-heap.hpp
//  number-partition
//
//  C++ Program to Implement a Max D-Heap
//

#ifndef d_heap_hpp
#define d_heap_hpp

#include <stdio.h>
#include <iostream>

/*
 * D-Heap Class
 */
class DHeap {
    private:
        // number of children per node
        int d;
        // max size of the heap
        int size;
        // current size of the heap
        int current_size;
        // pointer to an array that holds the heap's contents
        int64_t *array;
    
    public:
        /*
         * Constructor function
         * @param capacity : max capacity of the heap
         * @param num_children : # of children that each node has
         */
        DHeap(int capacity, int num_children);
        
        /*
         * Checks whether the heap is empty or not
         */
        bool IsEmpty();
        
        /*
         * Checks whether the heap is full or not
         */
        bool IsFull();
        
        /*
         * Gets the Parent Index from the Child Index
         * @param i : child index
         * @return : index of the parent
         */
        int GetParent(int i);
        
        /*
         * Gets the Kth child's Index from the Parent Index
         * @param i : parent index
         * @param k : k'th child
         * @return : index of the kth child
         */
        int GetKthChild(int i, int k);
    
        /*
         * Insert element into the heap
         * @param val : value to insert
         */
        void Insert(int64_t val);
        
        /*
         * Function BubbleUp
         * @param insert_pos : index of the element that needs to be Bubble'd up
         */
        void BubbleUp(int insert_pos);
        
        /*
         * Deletes the max from the heap and rebalances
         * @param max : reference to store the max element
         */
        void DeleteMax(int64_t &min);
        
        /*
         * Rearranges the tree rooted at parent_pos to be a MAX-HEAP
         * @param parent_pos : position of the parent index
         */
        void MaxHeapify(int parent_pos);
        
        /*
         * Prints heap for debugging and testing purposes
         */
        void PrintHeap();
};

#endif /* d_heap_hpp */
