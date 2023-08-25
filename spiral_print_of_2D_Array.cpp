#include <iostream>
#include <vector>
using namespace std;

/*
    Given matrix of 2D like this. 1 2 3
                                  4 5 6  = [1,2,3,6,9,8,7,4,5]
                                  7 8 9

    You need to print this in spiral order.
*/

vector<int> spiralPrint(vector<vector<int>> arr)
{
    vector<int> ans;

    int totalRows = arr.size();    // total rows in the arr.
    int totalCols = arr[0].size(); // total cols in the arr.

    int totalElements = totalCols * totalRows;

    int startRow = 0, startCol = 0;
    int endRows = totalRows - 1, endCols = totalCols - 1;

    int count = 0;
    while (count != totalElements)
    {
        // 1st Row
        for (int i = startCol; count < totalElements && i <= endCols; i++)
        {
            ans.push_back(arr[startRow][i]);
            count++;
        }
        startRow++;
        // cout<<endl;
        // cout<<"startRows -> "<<startRow<<endl;

        // last col
        for (int i = startRow; count < totalElements && i <= endRows; i++)
        {
            ans.push_back(arr[i][endCols]);
            count++;
        }
        endCols--;

        // last row
        for (int i = endCols; count < totalElements && i >= startCol; i--)
        {
            ans.push_back(arr[endRows][i]);
            count++;
        }
        endRows--;

        // first col
        for (int i = endRows; count < totalElements && i >= startRow; i--)
        {
            ans.push_back(arr[i][startCol]);
            count++;
        }
        startCol++;
    }
    return ans;
}

void print(vector<int> ans)
{
    cout << "program is in print function." << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    cout << endl;
}

int main()
{
    // vector<vector<int>> nums{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> nums{{1, 2, 3, 4, 5}};
    vector<int> ans = spiralPrint(nums);
    print(ans);
    return 0;
}