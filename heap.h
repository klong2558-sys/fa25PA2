
#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        data[size]=idx;
        upheap(size, weightArr);
        size++;
    }

    int pop(int weightArr[]) {

        if (size == 0) return -1;  // heap is empty
        int minIndex = data[0];
        data[0] = data[size - 1];
        size--;
        downheap(0, weightArr);
    }

    void upheap(int pos, int weightArr[]) {

        while (pos > 0) {
            int parent = (pos - 1) / 2;

            if (weightArr[data[pos]] < weightArr[data[parent]]) {
                swap(data[pos], data[parent]);
                pos = parent;
            }else {
                break;
            }
        }
    }

    void downheap(int pos, int weightArr[]) {
        while (pos < size) {
            int child = 2 * pos;

            if (weightArr[child] < weightArr[pos]) {
                swap(data[pos], data[child]);
                pos = child;
            }else {
                break;
            }
        }
    }
};

#endif