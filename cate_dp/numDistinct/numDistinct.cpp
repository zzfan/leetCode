/*************************************************************************
	> File Name: numDistinct.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Tue 06 Sep 2016 09:49:59 AM HKT
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//刚做完字符串编辑距离的，还是没有熟悉这种算法
//感觉自己的功底还是有点弱
int numDistinct(string s, string t)
{
    int m = s.size(), n = t.size();
    if(m<n) return 0;
    vector<vector<int> > dp(m+1, vector<int> (n+1, 0));
    for(int i = 0; i<=m; i++) dp[i][0] = 1;

    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[m][n];
}

