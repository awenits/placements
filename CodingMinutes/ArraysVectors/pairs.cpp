#include<bits/stdc++.h>

using namespace std;

//O(N*N)
vector<int> isPair(vector<int> arr, int target){
    vector<int> ans(2);
    for(int i=0; i<arr.size()-1; i++){
        for(int j=i+1; j<arr.size(); j++){
            if(arr[i]+arr[j] == target){
                ans[0] = arr[i];
                ans[1] = arr[j];
                return ans;
            }
        }
    }    
    return ans;
}

//O(N)
vector<int> isPairEffiecient(vector<int> arr, int target){
    vector<int> ans(2);
    unordered_set<int> s;
    
    for(int i=0; i<arr.size()-1; i++){
        if(s.find(target - arr[i]) != s.end()){
            ans[0] = target - arr[i];
            ans[1] = arr[i];
            return ans;
        }
        else{
            s.insert(arr[i]);
        }
    }
    
    return ans;
}


int main(){
    vector<int> arr = {10, 5, 2, 3, -6, 9, 11};
    int target = 4;
    vector<int> p = isPairEffiecient(arr, target);

    cout<<p[0]<<" "<<p[1]<<endl;

    return 0;
}