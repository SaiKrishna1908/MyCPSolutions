#include <iostream>
using namespace std;

int countTrailingZerosInFactorial(int n) {
    int count = 0;
    for (int i = 5; n / i >= 1; i *= 5) {
        count += n / i;
    }
    return count;
}

int main() {
    int n;    
    cin >> n;

    int trailingZeros = countTrailingZerosInFactorial(n);
    cout<< trailingZeros <<endl;

    return 0;
}
