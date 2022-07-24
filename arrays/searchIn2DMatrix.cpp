#include <bits/stdc++.h>

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    // idea is to convert 2D into 1D matrix
    int m = matrix.size(), n = matrix[0].size();
    int start = 0, end = n * m - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        // In 2d mtrix we need to know row and col to access an element
        // so calculating index assuming row major  
        int row = mid / n; 
        int col = mid % n;

        if (matrix[row][col] == target)
        {
            return true;
        }
        else if (matrix[row][col] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 13;

    cout<<searchMatrix(matrix, 13)<<endl;
    cout<<searchMatrix(matrix, 3)<<endl;
    return 0;
}