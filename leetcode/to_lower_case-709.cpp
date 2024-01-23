#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;


class Solution {
public:
    string toLowerCase(string s) {
        for(int i=0;i<s.length();i++) {
            int ascii = s[i];
            if (ascii >= 65 && ascii <= 90) {
                s[i] = (char) ( (ascii - 65) + ('a'));
            }
        }

        return s;
    }
};