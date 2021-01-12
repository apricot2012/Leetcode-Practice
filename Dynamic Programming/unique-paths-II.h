//
// Created by GHT on 1/11/2021.
//

#ifndef DYNAMIC_PROGRAMMING_UNIQUE_PATHS_II_H
#define DYNAMIC_PROGRAMMING_UNIQUE_PATHS_II_H
#include<vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        for(int i = 0 ; i < m; i++) {
            for(int j = 0 ; j < n; j++) {
                if(obstacleGrid[i][j] == 1)
                    obstacleGrid[i][j] = -1;
            }
        }
        if(obstacleGrid[0][0] == -1) return 0;
        for(int i = 0; i < m; i++){
            if(obstacleGrid[i][0] != -1)
                obstacleGrid[i][0] = 1;
            else break;
        }

        for(int i = 0; i < n; i++) {
            if(obstacleGrid[0][i] != -1)
                obstacleGrid[0][i] = 1;
            else break;
        }

        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(obstacleGrid[j][i] != -1) {
                    if(obstacleGrid[j - 1][i] == -1) {
                        obstacleGrid[j-1][i] = 0;
                    }
                    if(obstacleGrid[j][i-1] == -1) {
                        obstacleGrid[j][i-1] = 0;
                    }
                    obstacleGrid[j][i] = obstacleGrid[j - 1][i] + obstacleGrid[j][i - 1];
                }
            }
        }
        if(obstacleGrid[m-1][n-1] != -1)
            return obstacleGrid[m-1][n-1];
        else return 0;
    }
};

#endif //DYNAMIC_PROGRAMMING_UNIQUE_PATHS_II_H
