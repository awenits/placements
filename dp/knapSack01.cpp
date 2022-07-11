/*
  program for solving 0/1 knapsack problem.
*/

#include<iostream>
#include<vector>

using namespace std;

int solve(vector<int> weight, vector<int> value, int maxWeight, int currWeight, int index, vector<vector<int>> &dp){
    if(index >= weight.size() || currWeight > maxWeight){
        return 0;
    }
    
    if(dp[index][currWeight])
        return dp[index][currWeight];
    
    int notTaken = solve(weight, value, maxWeight, currWeight, index+1, dp);
    int taken;
    if(currWeight + weight[index] <= maxWeight)
        taken = value[index] + solve(weight, value, maxWeight, currWeight+weight[index], index+1, dp);
    
    return dp[index][currWeight] = max(notTaken, taken);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>> dp(n, vector<int>(maxWeight+1));   
    return solve(weight, value, maxWeight, 0, 0, dp);
}

int main() {
  vector<int> weight = {1, 2, 4, 5};
  vector<int> values = {5, 4, 8, 6};
  int maxWeight = 5;
  cout<<knapsack(weight, values, weight.size(), maxWeight);
  return 0;
}