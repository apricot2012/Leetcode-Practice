//
// Created by GHT on 1/10/2021.
//

#ifndef DYNAMIC_PROGRAMMING_LONGEST_VALID_PARENTHESES_H
#define DYNAMIC_PROGRAMMING_LONGEST_VALID_PARENTHESES_H
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int leftParen = 0;
        int rightParen = 0;
        int Paren[30010];
        int index = 0;
        int max = 0;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                Paren[i] = 1;
            } else if(s[i] == ')'){
                Paren[i] = 2;
            }
        }
        int flag = 1;

        int length = s.length();
        while(flag) {
            flag = 0;
            int frontptr = 0;
            int endptr = 0;
            for(int i = 0; i < length; i++) {
                if(Paren[i] == 1) {
                    int secondflag = 0;
                    frontptr = i;
                    for (int j = 1; i + j < length; j++) {
                        if (Paren[i + j] == 2) {
                            endptr = i + j;
                            flag = 1;
                            secondflag = 1;
                            break;
                        } else if (Paren[i + j] == 3) {
                            endptr++;
                        } else {
                            frontptr = 0;
                            endptr = 0;
                            break;
                        }
                    }
                    if (secondflag == 1) {
                        Paren[frontptr] = 3;
                        Paren[endptr] = 3;
                    }
                }
            }
        }
        int curmax = 0;
        for(int i = 0 ; i < length; i++) {

            if(Paren[i] == 3)
                curmax++;
            else {
                if(curmax > max)
                    max = curmax;
                curmax = 0;
            }
        }
        if(curmax > max)
            max = curmax;

        return max;
    }
};
#endif //DYNAMIC_PROGRAMMING_LONGEST_VALID_PARENTHESES_H
