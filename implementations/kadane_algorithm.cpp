/*
Write an efficient program to find the sum of contiguous subarray within 
a one-dimensional array of numbers that has the largest sum. 

*/

#include <iostream>

using namespace std;

int main() {

    int arr[] = {2,-1,8,-4,5,-2,3};
    int size = 7;

    int max_end_here = 0;
    int max_so_far = -1e9;

    for(int i=0;i<size;i++) {
        
        max_end_here = max_end_here + arr[i];

        if (max_end_here < 0) {
            max_end_here = 0;
        } else {
            max_so_far = max(max_so_far, max_end_here);
        }
    }

    cout<<max_so_far<<endl;
}