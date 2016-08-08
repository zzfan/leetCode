#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//超时
void rotate_my(vector<vector<int> > &matrix)
{
    int n = matrix.size();
    //转置
    for(int i = 0; i<n; i++){
        for(int j = i+1; i<n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    //左右翻转
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n/2; j++){
            swap(matrix[i][j], matrix[i][n-j-1]);
        }
    }
}

void rotate(vector<vector<int> > &matrix)
{
    int n = matrix.size();
    if(n == 0)return;
    for(int i = 0, len = n; i < n/2; i++, len -= 2)
    {//n/2 为旋转的圈数，len为第i圈中正方形的边长
        int m = len - 1;
        for(int j = 0; j < m; j++)
        {
            int tmp = matrix[i][i+j];
            matrix[i][i+j] = matrix[i+m-j][i];
            matrix[i+m-j][i] = matrix[i+m][i+m-j];
            matrix[i+m][i+m-j] = matrix[i+j][i+m];
            matrix[i+j][i+m] = tmp;
        }
    }
}
