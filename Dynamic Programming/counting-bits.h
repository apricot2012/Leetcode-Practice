//
// Created by GHT on 1/14/2021.
//

#ifndef DYNAMIC_PROGRAMMING_COUNTING_BITS_H
#define DYNAMIC_PROGRAMMING_COUNTING_BITS_H
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp;
        if(num == 0){
            dp.push_back(0);
            return dp;
        }
        dp.push_back(0);
        dp.push_back(1);
        int mult = 2;
        for(int i = 2; i <= num; i++) {
            if(i == mult * 2)
                mult*=2;
            dp.push_back(dp[i - mult] + 1);

        }
        return dp;
    }
};
#endif //DYNAMIC_PROGRAMMING_COUNTING_BITS_H
