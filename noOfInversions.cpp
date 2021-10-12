#include<bits/stdc++.h>

using namespace std;

int mergeSort(vector<int> v){

}


void count_inversion(vector<int> v, int i, int mid, int k, int j){


    while(i<=mid && k<=j){
        if(v[i] <= v[k]){
            b.push_back(v[i]);
            i++;
        }
        else{
            b.push_back(v[k]);
            k++;
        }
    }
    while(i<=mid){
        b.push_back(v[i]);
    }
    while(k<=j){
        b.push_back(v[k]);
    }
}


vector<int> noOfInversions(vector<int> v, int i, int j){
    if(i==j) return v;
    else{
        int mid = (i+j)/2;
        vector<int> s1 = noOfInversions(v, i, mid);
        vector<int> s2 = noOfInversions(v, mid+1, j);
        count_inversion(v, i, mid, mid+1, j);
    }
    return v;
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

    v = noOfInversions(v, 0, n-1);
    for(int i=0; i<n; i++){
        cout<<b[i]<<" ";
    }

    return 0;
}
