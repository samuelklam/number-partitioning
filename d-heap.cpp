//
//  d-heap.cpp
//  number-partition
//
//

#include "d-heap.hpp"

DHeap::DHeap(int capacity, int num_children) {
    size = capacity;
    current_size = 0;
    d = num_children;
    // initialize array to values of -1
    array = new int64_t[capacity]{-1};
}

bool DHeap::IsEmpty() {
    return current_size == 0;
}

bool DHeap::IsFull() {
    return current_size == size;
}

int DHeap::GetParent(int i) {
    return (i - 1) / d;
}

int DHeap::GetKthChild(int i, int k) {
    return (d * i) + k;
}

/*
 * Insert element into the heap and Bubble Up to maintain heap properties
 */
void DHeap::Insert(int64_t val) {
    if (IsFull()) {
        std::cout << "Warning! We've reached the max heap size." << std::endl;
        return;
    }
    array[current_size] = val;
    BubbleUp(current_size);
    current_size++;
}

void DHeap::BubbleUp(int insert_pos) {
    while (insert_pos > 0 && array[insert_pos] > array[GetParent(insert_pos)]) {
        int parent_pos = GetParent(insert_pos);
        std::swap(array[insert_pos], array[parent_pos]);
        insert_pos = parent_pos;
    }
}

int64_t DHeap::DeleteMax(int64_t max) {
    if (IsEmpty()) {
        std::cout << "Warning! There are no elements in the heap currently." << std::endl;
        return max;
    }
    max = array[0];
    array[0] = array[current_size-1];
    current_size--;
    MaxHeapify(0);
    return max;
}

void DHeap::MaxHeapify(int parent_pos) {
    
    int swap_pos = parent_pos;
    int swap_bool = 1;
    
    while (swap_bool) {
        // iterate over the children to find the largest value to swap with
        for (int i = 1; i < d + 1; i++) {
            int child_pos = GetKthChild(parent_pos, i);
            
            // make sure that the child actually exists
            if (child_pos < current_size) {
                // greedily update
                if (array[child_pos] > array[swap_pos]) {
                    swap_pos = child_pos;
                }
            }
        }
        if (swap_pos != parent_pos) {
            std::swap(array[parent_pos], array[swap_pos]);
            parent_pos = swap_pos;
        }
        else {
            swap_bool = 0;
        }
    }
}

void DHeap::PrintHeap() {
    for (int i = 0; i < current_size; i++)
        std::cout << "[" << array[i] << "], ";
    std::cout << std::endl;
}
