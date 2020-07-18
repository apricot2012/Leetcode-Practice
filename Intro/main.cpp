#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
void recur(vector<int> *nums, int pos, vector<int> cur, vector<vector<int>> *res){
    int i;
    res->push_back(cur);
    for(i = pos; i < nums->size(); i++) {
        cur.push_back((*nums)[i]);
        recur(nums, i+1, cur, res);
        cur.pop_back();
    }
}


int main() {
    vector<int> nums;
    int input;
    while(cin>>input) {
       nums.push_back(input);
    }
    vector<vector<int>> result;
    vector<int> cur;
    recur(&nums, 0, cur, &result);
    int i, j;
    for(i = 0; i < result.size(); i++) {
        for(j = 0; j < result[i].size(); j++) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

