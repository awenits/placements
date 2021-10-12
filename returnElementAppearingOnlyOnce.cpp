#include<bits/stdc++.h>
using namespace std;

int findUniqueElement(vector<int> nums, int i, int j){
    //if unique element doesn't exist in array
    if(i>j || nums.size()%2 == 0){
        return -1;
    }

    if(i==j){
        return nums[i];
    }

    int mid=(i+j)/2;
    if (mid % 2 == 0) {
        if (nums[mid] == nums[mid + 1])
            return findUniqueElement(nums, mid + 2, j);
        else
            return findUniqueElement(nums, i, mid);
    }
    else{
        if (nums[mid] != nums[mid + 1])
            return findUniqueElement(nums, mid + 1, j);
        else
            return findUniqueElement(nums, i, mid-1);
    }
}



int main(){
    vector<int> nums;
    int n, ele;
    cout<<"Enter the size of of sorted array: ";
    cin>>n;
    cout<<"Enter the elements(space separated) of sorted array: ";
    for(int i=0; i<n; i++){
        cin>>ele;
        nums.push_back(ele);
    }

    cout<<findUniqueElement(nums, 0, n-1);

    return 0;
}
