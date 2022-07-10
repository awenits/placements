/*
  program to check if there exist a subsequence/subset 
  in given array whose sum equals to k.
*/

#include<iostream>
#include<vector>

using namespace std;

bool subsequences(vector<int> v, int sum, int k, int i, vector<vector<int>> &mp){
  if(sum == k){
      return true;
  }

  if(i >= v.size())
  {
    return false;
  }
  
    if(mp[i][sum] != -1){
        return mp[i][sum];
    }
    
  bool withoutAdd = subsequences(v, sum, k, i+1, mp);
  bool withAdd = false;
  if(sum+v[i] <= k)
      withAdd = subsequences(v, sum+v[i], k, i+1, mp);
  
    return mp[i][sum] = (withAdd || withoutAdd);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> mp(n+1, vector<int>(k+1, -1));
    return subsequences(arr, 0, k, 0, mp);
}


int main() {
  vector<int> v = {4, 3, 2, 1};
  int n = 4;
  int k = 5;
  cout<<subsetSumToK(n, k, v);
  return 0;
}