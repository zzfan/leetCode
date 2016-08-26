/*************************************************************************
	> File Name: minimumTotal.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Fri 22 Apr 2016 10:23:03 AM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int minimumTotal(vector<vector<int> >& triangle)
{
    //比较简单的一个动态规划题
    int raws = triangle.size();
    if(raws == 0 || triangle[0].size() == 0)
        return 0;
    vector<int> dp(triangle.back());

    for(int i = raws-2; i >= 0; i--){
        for( int j = 0; j<=i; j++ ){
            dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
        }
    }

    return dp[0];
}


