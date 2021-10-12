#include<bits/stdc++.h>
using namespace std;

int main(){
    int A[5];
    A[0] = 100;
    A[1] = 200;     //A[1] == *(A+1)
    cout<<*(A+1)<<endl;  //address of first element

    return 0;
}
