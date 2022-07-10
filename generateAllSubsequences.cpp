#include<iostream>
#include<vector>

using namespace std;

void subsequences(vector<int> v, vector<vector<int>> &ans, vector<int> temp, int i){
  if(i >= v.size())
  {
    ans.push_back(temp);
    return;
  }
  
  subsequences(v, ans, temp, i+1);
  temp.push_back(v[i]);
  subsequences(v, ans, temp, i+1);
}


int main() {
  vector<int> v = {3, 1, 2};
  vector<vector<int>> ans;
  vector<int> temp;
  subsequences(v, ans, temp, 0);
  cout<<"Number of subsequences: "<<ans.size()<<endl;
  for(auto vec: ans){
    for(auto n:vec){
      cout<<n<<" ";
    }
    cout<<endl;
  }

  return 0;
}