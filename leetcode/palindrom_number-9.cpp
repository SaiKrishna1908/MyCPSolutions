#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;


class Solution {
public:

    
    bool isPalindrome(int x) {

        if (x < 0) {
            return false;
        }

        vector<int> digits;
        
        while(x>0) {
            digits.push_back(x%10);
            x /= 10;
        }

        int left = 0;
        int right = digits.size()-1;

        while(left < right) {
            if (digits[left] != digits[right]) {
                return false;;
            }

            left++;
            right--;            
        }

        return true;
    }
};