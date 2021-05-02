/*
 * Source File: main.cpp 
 * Date: 4/28/21 
 * Author: Ahmad Abdalmageed.
 */

#include "include/MergeSort.hpp"
#include <random>
#include <algorithm>

int NaiveCount(IntVector1D a, int n);


/*
 * Main Stress Testing Function:
 * 1- First Generate a Random Size Array with Random Numbers.
 * 2- Loop a Selected Number of Iterations and test both Naive and Optimized Solutions.
 * 3- Stop if answers are not equal.
 *
 */
int main(){
    // Random Generator Instantiation
    std::random_device rnd_device;
    std::default_random_engine rnd_engine{rnd_device()};
    std::uniform_int_distribution<int> dist{0, 100};

    // Random Number Generator from a Uniform Dist of 0 to 100
    auto gen = [&dist, &rnd_engine](){
        return dist(rnd_engine);
    };

    // Select Number of Iterations
    int iterations = 10;

    // Stress Testing
    while (iterations > 0){
        int cnvs = 0;
        int size = gen();
        IntVector1D x(size);

        std::generate(x.begin(), x.end(), gen);

        printf("\nGenerated Array: ");
        PrintVec(x);
        IntVector1D res1 = MergeSort(x, cnvs);
        int res2 = NaiveCount(x, size);

        if(res2 != cnvs){
            PrintVec(x);
            printf("Merge Res: %d\n", cnvs);
            printf("Naive Res: %d\n", res2);
            break;
        }
        printf("\nResults are Equal ");
        iterations--;
    }

    return 0;
}

int NaiveCount(IntVector1D a, int n){
    int i, j, c = 0;
    for(i = 0; i < n; i++) {
        for(j = i+1; j < n; j++)
            if(a[i] > a[j])
                c++;
    }
    return c;
}
