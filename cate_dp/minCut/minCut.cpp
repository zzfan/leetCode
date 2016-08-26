/*************************************************************************
	> File Name: minCut.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Fri 26 Aug 2016 03:29:35 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define INT_MAX 0x7fffffff

int minCut(string s)
{
    int len = s.size();
    if(len<=1) return 0;
    vector<vector<bool> > ispalin(len+1, vector<bool>(len+1, false));
    //求出每个子串是否时palin
    for(int i = len-1; i>=0; i--){
        for(int j = i; j<len; j++){
            if((i+1>=j-1 || ispalin[i+1][j-1]) && s[i] == s[j]){
                ispalin[i][j] = true;
            } 
        }
    }

    //求出最小的分割次数
    vector<int> dp(len+1, INT_MAX);
    dp[0] = -1;
    for(int i = 1; i<=len; i++){
        for(int j=i-1; j>=0; j--){
            if(ispalin[j][i-1]){
                dp[i] = min(dp[i], dp[j]+1);
            }
        }
    }
    return dp[len];
}

int main()
{
    string s;
    cin >> s;
    int res = minCut(s);
    cout << res << endl;
}

