/*************************************************************************
	> File Name: wordBreak.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Tue 06 Sep 2016 08:58:43 PM HKT
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

bool wordBreak(string s, unordered_set<string> &wordDict)
{
    vector<bool> dp(s.size()+1, false);
    dp[0] = true;
    for(int i = 0; i<s.size(); i++){
        for(int j = i; j>=0; j--){
            if(dp[j] && wordDict.count(s.substr(j, i-j+1)) != 0){
                dp[i+1] = true;
                break;
            }
        }
    }
    return dp[s.size()];
}

