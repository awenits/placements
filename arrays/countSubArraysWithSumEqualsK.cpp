#include<bits/stdc++.h>

using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    for (int i = 1; i < nums.size(); i++)
    {
        nums[i] += nums[i - 1];
    }

    unordered_map<int, int> mp; // declare an unordered map

    int ans = 0; // to store the number of our subarrays having sum as 'k'

    for (int i = 0; i < nums.size(); i++) // traverse from the prefix array
    {
        if (nums[i] == k) // if it already becomes equal to k, then increment ans
            ans++;

        // now, as we discussed find whether (prefix[i] - k) present in map or not
        if (mp.find(nums[i] - k) != mp.end())
        {
            ans += mp[nums[i] - k]; // if yes, then add it our answer
        }

        mp[nums[i]]++; // put prefix sum into our map
    }

    return ans; // and at last, return our answer
}

int main(){
    vector<int> nums = {1, 2, 3};
    int k=3;
    cout<<subarraySum(nums, 3)<endl;
    return 0;
}