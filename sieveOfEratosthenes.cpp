/*
    Given a number n, print all primes smaller than or equal to n. It is also given that n is a small number.
    O(n*log(log(n)))
    n/2 + n/3 + n/5 + n/7 + ... + p
    n * (1/2 + 1/3 + 1/5 + 1/7 + ....p)
    n * log(log(n))             --> harmonic mean of series
*/

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n = 50;

    vector<bool> isPrime(n+1, true);
    
    for(int i=2; i*i <= n; i++){
        if(isPrime[i]){
            for(int j=2; i* j <= n; j++){
                isPrime[i*j] = false;
            }
        }
    }

    for(int i=2; i<n+1; i++){
        if(isPrime[i])
            cout<<i<<" ";
    }

    return 0;
}