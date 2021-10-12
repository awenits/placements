#include<bits/stdc++.h>

using namespace std;

void isTarget(vector<int> v, int target){
    unordered_map<int, int> tracker;

    for(int i=0; i<v.size(); i++){
        if(tracker.count(v[i])>0){
            cout<<"Pair found ("<<v[tracker[v[i]]]<<","<<v[i]<<")"<<endl;
            return;
        }
        else{
            tracker[target-v[i]] = i;
        }
    }
    cout<<"No pair exists"<<endl;
}

int main(){
    vector<int> v;
    int n, target, ele;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<<"Enter "<<n<<" elements: ";
    for(int i=0; i<n; i++){
        cin>>ele;
        v.push_back(ele);
    }
    cout<<"Enter the value of target: ";
    cin>>target;
    isTarget(v, target);

    return 0;
}
