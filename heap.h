
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
        if (size == 0) return -1;
        int minIndex = data[0];
        if (size == 1) {
            size = 0;
            return minIndex;
        }

        data[0] = data[size - 1];
        size--;
        downheap(0, weightArr);
        return minIndex;
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
        while (true) {
            int left = 2 * pos + 1;
            int right = 2 * pos + 2;
            int smallest = pos;

            // find smaller of left or right
            if (left < size && weightArr[data[left]] < weightArr[data[smallest]])
                smallest = left;
            if (right < size && weightArr[data[right]] < weightArr[data[smallest]])
                smallest = right;

            if (smallest != pos) {
                swap(data[pos], data[smallest]);
                pos = smallest;
            } else break;
        }
    }
};

#endif