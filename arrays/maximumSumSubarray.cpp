/*
    Given an integer array, return maximum subarray sum.
    A subarray is a contiguous part of an array.
*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int maxSubArrayEfficient(vector<int>& nums) {
    int n = nums.size(), maxSum = nums[0], currSum = nums[0];
    for(int i=1; i<n; i++){
        if(currSum < 0){
            currSum = nums[i];
        }
        else{
            currSum += nums[i];
        }

        maxSum = max(currSum, maxSum);
    }

    return maxSum;
}

int maxSubArray(vector<int>& nums) {
    int n = nums.size(), maxSum = INT_MIN;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=n-i; j++){
            int tempSum = 0;
            for(int k=j; k<j+i; k++)
                tempSum += nums[k];
            maxSum = max(tempSum, maxSum);
        }
    }

    return maxSum;
}

int main(){
    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(nums)<<endl;
    cout<<maxSubArrayEfficient(nums)<<endl;
    return 0;
}