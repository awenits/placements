#include<bits/stdc++.h>

using namespace std;

int majorityElement(vector<int> v, int n){
    int majorElement=0, majorCnt=0;

    for(int num: v){
        if(majorCnt == 0){
            majorElement = num;
            majorCnt += 1;
        }
        else{
            if(majorElement == num){
                majorCnt += 1;
            }
            else{
                majorCnt -= 1;
            }
        }
    }

    return majorElement;
}

int main(){
    vector<int> v;
    int n, ele;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<<"Enter "<<n<<" elements: ";
    for(int i=0; i<n; i++){
        cin>>ele;
        v.push_back(ele);
    }

    cout<<"Majority Element is: "<<majorityElement(v, n);

    return 0;
}
