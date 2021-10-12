#include<bits/stdc++.h>
using namespace std;

int fib1(int n){
    if(n == 0 || n == 1)
        return n;
    else
        return fib1(n-1) + fib1(n-2);
}

int dp_fib(int n, vector<int> &table){
    if(n == 0 || n == 1)
        return n;
    else{
        if(table[n-2] == -1)
            table[n-2] = dp_fib(n-2, table);
        if(table[n-1] == -1)
            table[n-1] = dp_fib(n-1, table);
        table[n] = table[n-1] + table[n-2];
        return table[n];
    }
}

int fib2(int n){
    vector<int> table(n+1, -1);
    return dp_fib(n, table);
}

int main(){
    cout<<fib1(6)<<endl;
    return 0;
}
