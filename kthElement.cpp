#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr1;
    vector<int> arr2;
    vector<int> finalSortedArr;
    int N, M, k, ele;
    cout<<"Enter the size of arr1: ";
    cin>>N;
    cout<<"Enter the elements(space separated) of arr1: ";
    for(int i=0; i<N; i++){
        cin>>ele;
        arr1.push_back(ele);
    }
    cout<<"Enter the size of arr2: ";
    cin>>M;
    cout<<"Enter the elements(space separated) of arr2: ";
    for(int i=0; i<M; i++){
        cin>>ele;
        arr2.push_back(ele);
    }
    cout<<"Enter the value of k: ";
    cin>>k;

    int i=0, j=0, p=0;
    while(i<N && j<M){
        if(arr1[i] < arr2[j]){
            finalSortedArr.push_back(arr1[i]);
            i++;
        }
        else{
            finalSortedArr.push_back(arr2[j]);
            j++;
        }
    }
    while(i<N){
        finalSortedArr.push_back(arr1[i]);
        i++;
    }
    while(j<M){
        finalSortedArr.push_back(arr2[j]);
        j++;
    }

    cout<<"The "<<k<<"th element of the final sorted array is: "<<finalSortedArr[k-1];

    return 0;
}
