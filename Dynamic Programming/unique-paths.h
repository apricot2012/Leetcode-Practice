//
// Created by GHT on 1/11/2021.
//

#ifndef DYNAMIC_PROGRAMMING_UNIQUE_PATHS_H
#define DYNAMIC_PROGRAMMING_UNIQUE_PATHS_H
#include<cstring>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[110][110];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++)
            dp[0][i] = 1;
        for(int i = 0; i < m; i++)
            dp[i][0] = 1;
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                dp[j][i] = dp[j - 1][i] + dp[j][i - 1];
            }
        }
        return dp[m-1][n-1];
    }
};
#endif //DYNAMIC_PROGRAMMING_UNIQUE_PATHS_H
