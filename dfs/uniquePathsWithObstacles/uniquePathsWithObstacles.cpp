/*************************************************************************
	> File Name: uniquePathsWithObstacles.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Thu 14 Jul 2016 03:11:04 PM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

//这段代码一遍过，哈哈！
int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
{
    if(obstacleGrid.size() < 1) return 0;
    int row = obstacleGrid.size(), col = obstacleGrid[0].size();
    vector<vector<int> > step(row, vector<int>(col, 0));

    int flag = 0;
    for(int i = 0; i<row; i++){
        if(0 == flag && obstacleGrid[i][0] == 0)
        step[i][0] = 1;
        if(obstacleGrid[i][0] == 1)
        flag = 1;
        if(flag == 1)
        step[i][0] = 0;
    }
    flag = 0;
    for(int i = 0; i<col; i++){
        if(0 == flag && obstacleGrid[0][i] == 0)
            step[0][i] = 1;
        if(obstacleGrid[0][i] == 1)
            flag = 1;
        if(flag == 1)
            step[0][i] = 0;
    }
    for(int i = 1; i<row; i++){
        for(int j = 1; j<col; j++){
            if(obstacleGrid[i][j] == 1)
            step[i][j] = 0;
            else
            step[i][j] = step[i-1][j] + step[i][j-1];
        }
    }
    return step[row-1][col-1];
}

int main()
{
    vector<vector<int> > temp;
    int m, n;
    cin >> m >> n;
    for(int i = 0; i<m; i++){
        vector<int> v(n);
        for(int j = 0; j<n; j++){
            cin >> v[j];
        }
        temp.push_back(v);
    }
    cout << uniquePathsWithObstacles(temp) << endl;
}

