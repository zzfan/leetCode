/*************************************************************************
	> File Name: numSquares.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Tue 07 Jun 2016 03:28:24 PM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
#define min(a,b) ((a)>(b)?(a):(b))
using namespace std;

//这个解法我是没看懂啊
int numSquares(int n)
{
    vector<int> dp(n+1, 0x7fffffff);
    for(int i = 0; i*i <= n; i++){
        dp[i*i] = 1;
    }

    for(int i = 2; i<=n; i++){
        for(int j = 1; j*j<=i; j++)
            dp[i] = min(dp[i], dp[i-j*j] + 1);
    }

    return dp[n];
}
