#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int main() {
    int m,n;
    cin>>m>>n;
    vector<vector<int>> grid;
    for(int i = 0; i < m; i++) {
        vector<int> v;
        for(int j = 0; j < n; j++) {
            int t;
            cin>>t;
            v.push_back(t);
        }
        grid.push_back((v));
    }

    for(int i = 0 ; i < m; i++) {
        for(int j = 0 ; j < n; j++) {
            if(grid[i][j] == 1)
                grid[i][j] = -1;
        }
    }

    for(int i = 0; i < m; i++){
        if(grid[i][0] != -1)
            grid[i][0] = 1;
    }

    for(int i = 0; i < n; i++) {
        if(grid[0][i] != -1)
            grid[0][i] = 1;
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(grid[j][i] != -1) {
                if(grid[j - 1][i] == -1) {
                    grid[j-1][i] = 0;
                }
                if(grid[j][i-1] == -1) {
                    grid[j][i-1] = 0;
                }
                grid[j][i] = grid[j - 1][i] + grid[j][i - 1];
            }
        }
    }
    cout<<grid[m-1][n-1];
    return 0;
}
