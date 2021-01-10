//
// Created by GHT on 1/9/2021.
//
#include <iostream>
#include <string.h>
#include <vector>


#ifndef DYNAMIC_PROGRAMMING_TARGET_SUM_H
#define DYNAMIC_PROGRAMMING_TARGET_SUM_H
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S)  {
        int dp[31][2010];
        memset(dp, 0, sizeof(dp));
        dp[1][1000 + nums[0]]++;
        dp[1][1000 - nums[0]]++;
        for(int i = 1 ; i < nums.size(); i++) {
            for(int j = 0; j < 2010; j++) {
                if(dp[i][j] != 0) {
                    dp[i + 1][j + nums[i]] += dp[i][j];
                    dp[i + 1][j - nums[i]] += dp[i][j];
                }
            }
        }
        if(S <= 1000)
            return dp[nums.size()][1000 + S];
        else return 0;
    }
};
#endif //DYNAMIC_PROGRAMMING_TARGET_SUM_H
