/*************************************************************************
	> File Name: uniquePaths.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Fri 10 Jun 2016 11:15:42 AM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

//回溯法
int uniquePaths_backTrack(int m, int n)
{
    if(m==1||n==1) return 1;
    return uniquePaths_backTrack(m-1, n) + uniquePaths_backTrack(m, n-1);
}

//动态规划
int uniquePaths(int m, int n)
{
    vector<vector<int> > v(m, vector<int>(n, 1));
    for(int i = 1; i<m; ++i){
        for(int j = 1; j<n; ++j){
            v[i][j] = v[i-1][j]   + v[i][j-1];
        }
    }
    return v[m-1][n-1];
}

//改进算法
int uniquePaths1(int m, int n)
{
    vector<int> v(n,1);
    for(int i = 1; i<m; ++i){
        for(int j = 1; j<n; ++j){
            v[j] += v[j-1];
        }
    }
    return v[n-1];
}

int main()
{
    int m, n;
    while(cin >> m >> n){
        cout << uniquePaths(m, n) << endl;
    }
}
