//
// Created by yerik on 9/15/24.
//

#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <vector>



class Sorters {
public:
    void bubbleSort(std::vector<int>& arr);
    void selectionSort(std::vector<int>& arr);
    void mergeSort(std::vector<int>& arr);

private:
    void merge(std::vector<int>& arr, int left, int mid, int right);
    void mergeSortHelper(std::vector<int>& arr, int left, int right);
};


#endif //ALGORITHMS_H
