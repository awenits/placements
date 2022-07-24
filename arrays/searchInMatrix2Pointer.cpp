/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix.
This matrix has the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
*/

#include <bits/stdc++.h>

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size(), n = matrix[0].size();
    int rowIndex = 0, colIndex = n - 1;

    while (rowIndex < m && colIndex >= 0)
    {
        int ele = matrix[rowIndex][colIndex];

        if (ele == target)
            return true;
        else if (ele < target)
        {
            rowIndex++;
        }
        else
        {
            colIndex--;
        }
    }

    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target = 13;

    cout << searchMatrix(matrix, 13) << endl;
    cout << searchMatrix(matrix, 0) << endl;
    return 0;
}