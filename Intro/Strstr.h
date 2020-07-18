//
// Created by HP on 2020/7/17.
//

#ifndef INTRO_STRSTR_H
#define INTRO_STRSTR_H

#include <string>

using namespace std;
class Strstr {
public:
    int strStr(string haystack, string needle) {
        int haylen = haystack.length();
        int needlen = needle.length();
        int pos = -1;

        if(needlen == 0)
            return 0;

        for (int i = 0; i < haylen - needlen + 1; i++) {
            if (haystack[i] == needle[0]) {
                int j = 0;
                while (i + j < haylen && haystack[i + j] == needle[j]) {
                    if (j == needlen - 1) {
                        pos = i;
                        return pos;
                    }
                    j++;
                }
            }
        }
        return pos;
    }
};


#endif //INTRO_STRSTR_H
