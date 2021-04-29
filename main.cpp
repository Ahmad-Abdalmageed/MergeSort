/*
 * Source File: main.cpp 
 * Date: 4/28/21 
 * Author: Ahmad Abdalmageed.
 */

#include "include/MergeSort.hpp"

int main(){
    IntVector1D x = {10, 3, 8, 9, 1, 5, 6};

    // DEBUG Error
    IntVector1D res = MergeSort(x);
    PrintVec(res);
    return 0;
}