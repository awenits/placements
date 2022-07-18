#include<bits/stdc++.h>

using namespace std;

int main(){
    /*
        6
        6 0 0 0 0 5
    */
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    vector<int> v(n);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    //prefix sum array
    for(int i=1; i<n; i++){
        v[i] = v[i-1] + v[i];
    }

    /*
       solution to problem: https://codeforces.com/problemset/problem/1398/C
    */

    //stores count of good subarrays
    int count=0;

    // Pick starting point
    for (int l=0; l <n; l++)
    {
        // Pick ending point
        for (int r=l; r<n; r++)
        {
            if(l==0){
                if(v[r]-r == 0-l+1){
                    count++;
                }
            }
            else{
                if(v[r]-r == v[l-1]-l+1){
                    count++;
                }
            }
        }
    }
    cout<<count<<endl;
    return 0;
}