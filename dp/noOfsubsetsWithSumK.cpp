/*
  program to count number of subsequence/subset 
  in given array whose sum is equal to k.
*/

#include<iostream>
#include<vector>

using namespace std;

int subsets(vector<int> v, int sum, int k, int i, vector<vector<int>> &mp){
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
    
  int withoutAdd = subsets(v, sum, k, i+1, mp);
  int withAdd = false;
  if(sum+v[i] <= k)
      withAdd = subsets(v, sum+v[i], k, i+1, mp);
  
    return mp[i][sum] = withAdd + withoutAdd;
}

int findWays(vector<int> &num, int tar)
{
    vector<vector<int>> mp(num.size(), vector<int>(tar+1, -1));
    return subsets(num, 0, tar, 0, mp);
}

int main() {
  vector<int> v = {1, 2, 2, 3};
  int k = 4;
  cout<<"Number of subsets with sum "<<k<<" are "<<findWays(v, k)<<endl;
  return 0;
}