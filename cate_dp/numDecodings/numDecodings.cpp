/*************************************************************************
	> File Name: numDecodings.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Sun 04 Sep 2016 04:10:05 PM HKT
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int numDecodings(string s)
{
    if(s.empty() || s[0] < '1' || s[0] > '9') return 0;
    int n = s.size();
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;

    for(int i = 1; i<n; i++){
        if(s[i] < '0' || s[i] > '9') return 0;
        int temp = (s[i-1] - '0')*10 + s[i] - '0';
        if(temp <= 26 && temp > 9) dp[i+1] += dp[i-1];
        if(s[i] != '0') dp[i+1] += dp[i];
        if(dp[i+1] == 0) return 0;
    }
    return dp[n];
}

