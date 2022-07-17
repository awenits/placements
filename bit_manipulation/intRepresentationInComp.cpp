/* program to print how integers are represented in computer */
#include<iostream>
#include<climits>

using namespace std;

void print32BitsOfInt(int n){
    for(int i=31; i>=0; i--){
        //checks if (i+1)th bit is set or not
        if((1<<i) & n){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    cout<<endl;
}

int main(){
    print32BitsOfInt(INT_MIN); //10000000000000000000000000000000
    print32BitsOfInt(INT_MAX); //01111111111111111111111111111111
    print32BitsOfInt(3);       //00000000000000000000000000000011
    print32BitsOfInt(-3);      //11111111111111111111111111111101
    print32BitsOfInt(5);       //00000000000000000000000000000101
    print32BitsOfInt(-5);      //11111111111111111111111111111011
    return 0;
}