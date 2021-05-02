/*
 * Source File: MergeSort.hpp 
 * Date: 4/28/21 
 * Author: Ahmad Abdalmageed.
 */


#ifndef MERGESORT_MERGESORT_HPP
#define MERGESORT_MERGESORT_HPP

#include <iostream>
#include <vector>

typedef  std::vector<int> IntVector1D ;

IntVector1D MergeSort(IntVector1D src, int &cnvs);
IntVector1D SplitVec(const IntVector1D& src, int IdxStart, int IdxEnd);
void PrintVec(const IntVector1D &src);
IntVector1D Merge(IntVector1D left, IntVector1D right, int &cnvs);

#endif //MERGESORT_MERGESORT_HPP
