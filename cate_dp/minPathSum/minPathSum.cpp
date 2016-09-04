/*************************************************************************
	> File Name: minPathSum.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Sat 03 Sep 2016 10:23:24 PM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minPathSum(vector<vector<int> > &grid)
{
    int m = grid.size(), n = grid[0].size();
    if(m == 0 || n == 0) return 0;
    vector<vector<int> > sum(m, vector<int> (n, 0));
    sum[m-1][n-1] = grid[m-1][n-1];
    for(int i = m-2; i>=0; i--){
        sum[i][n-1] = sum[i+1][n-1] + grid[i][n-1];
    }
    for(int i = n-2; i>=0; i--){
        sum[m-1][i] = sum[m-1][i+1] + grid[m-1][i];
    }
    for(int i = m-2; i>=0; i--){
        for(int j = n-2; j>=0; j--){
            sum[i][j] = grid[i][j] + min(sum[i+1][j], sum[i][j+1]);
        }
    }
    return sum[0][0];
}

