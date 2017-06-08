#ifndef _RANDOM_H_
#define _RANDOM_H_

#include <stdlib.h>
#include <time.h>
#include <vector>
using std::vector;
bool _HASSEED_ = false;

void _setSeed(){
    srand((unsigned)time(NULL));
    _HASSEED_ = true;
}
template <typename T>
inline T random_number(T range){
    if(!_HASSEED_){
        _setSeed();
    }
    rand();
    double rat = rand() / double(RAND_MAX);
    return range*rat;
}

template <typename T>
vector<T> random_numbers(T range,int count){
    int i(0);
    vector<T> nums(count);
    if(!_HASSEED_){
        _setSeed();
    }
    while(i<count){
        nums[i] = random_number<T>(range);
        i++;
    }
    return nums;
}

template <typename T>
void show_vector(vector<T> arr){
    std::cout<<std::endl;
    for(auto item : arr){
        std::cout<<item<<" ";
    }
}

#endif
