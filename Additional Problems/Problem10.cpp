#include <iostream>
#include <math.h>
using namespace std;
bool isPrime(long long int n){
    for (int i = 2; i < (int)sqrt(n)+1; i++){
        if (fmod(n, i) == 0){
            return false;
        }
    }
    return true;
}
int main() {
    long long sum = 0;
    for (long long int i = 2; i < 2000000; i++) {
        if (isPrime(i)){
            sum += i;
        }
    }

    cout << sum;
}