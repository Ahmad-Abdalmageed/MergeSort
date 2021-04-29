/*
 * Source File: MergeSort.cpp 
 * Date: 4/28/21 
 * Author: Ahmad Abdalmageed.
 */

#include "../include/MergeSort.hpp"

IntVector1D MergeSort(IntVector1D src){
    if(src.size() == 1){
        return src;
    }
    int start = 0;
    int end = (int) src.size() - 1;
    int mid = (end - start) / 2;
    IntVector1D LVector = MergeSort(SplitVec(src, 0, mid));
    IntVector1D RVector = MergeSort(SplitVec(src, mid+1, end));

    IntVector1D out = Merge(LVector, RVector);
    return out;
}
/*
 * SLice a One Dimensional Vector
 */
IntVector1D SplitVec(const IntVector1D& src, int IdxStart, int IdxEnd){
    int size = IdxEnd - IdxStart;
    IntVector1D out(size + 1);
    auto begin = src.begin() +IdxStart;
    auto end = src.begin() + IdxEnd + 1;
    std::copy(begin, end, out.begin());

    return out;
}
/*
 * Merge Two Arrays in a Sorted Manner
 */
IntVector1D Merge(IntVector1D left, IntVector1D right){
    int size = (int)(left.size() + right.size());
    int count = 0;
    IntVector1D out(size);

    while (count < size){
        if(left[0] < right[0] && !left.empty()){
            out[count] = left[0];
            left.erase(left.begin());
        } else if (right[0] < left[0] && !right.empty()){
            out[count] = right[0];
            right.erase((right.begin()));
        } else {
            if (!left.empty()){
                for(int i : left){
                    out[count] = i;
                    count++;
                }
            }
            if (!right.empty()){
                for(int i : right){
                    out[count] = i;
                    count++;
                }
            }
        }
        count++;
    }
    return out;
}
/*
 * Print a One Dimensional Vector
 */
void PrintVec(const IntVector1D &src){
    for(auto &element: src){
        printf("%d ", element);
    }
    printf("\n");
}

