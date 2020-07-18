//
// Created by HP on 2020/7/18.
//

#ifndef INTRO_SUBSETS_78_H
#define INTRO_SUBSETS_78_H
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> cur;
        recur(&nums, 0, cur, &result);
        return result;
    }

    void recur(vector<int> *nums, int pos, vector<int> cur, vector<vector<int>> *res){
        int i;
        res->push_back(cur);
        for(i = pos; i < nums->size(); i++) {
            cur.push_back((*nums)[i]);
            recur(nums, i+1, cur, res);
            cur.pop_back();
        }
    }
};


#endif //INTRO_SUBSETS_78_H
