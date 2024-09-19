//
// Created by yerik on 9/18/24.
//

#ifndef MEDICIONES_H
#define MEDICIONES_H

#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <stdexcept>
#include "Algorithms.h"
#include "LinkedList.h"
#include "BinaryTree.h"

class MeasureTime {
public:
    double measureTime(const std::string& func, std::vector<int>& data, int caso);
};

#endif // MEDICIONES_H

