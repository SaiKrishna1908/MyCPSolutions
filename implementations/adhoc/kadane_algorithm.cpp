/*
Write an efficient program to find the sum of contiguous subarray within 
a one-dimensional array of numbers that has the largest sum. 

*/

#include <iostream>

using namespace std;

int main() {

    int arr[] = {2,-1,8,-4,5,-2,3};
    int size = 7;
    // current running sum
    int currentSum = 0;

    // maximum sum we saw so far
    int maxSoFar = -1e9;

    for(int i=0;i<size;i++) {
        
        currentSum = currentSum + arr[i];

        if (currentSum < 0) {
            currentSum = 0;
        } else {
            maxSoFar = max(maxSoFar, currentSum);
        }
    }

    cout<<maxSoFar<<endl;
}