/*************************************************************************
	> File Name: partition.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Mon 20 Jun 2016 03:13:33 PM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//这种需要输出所有结果的基本上都是DFS的解法
vector<vector<string> > partition(string s)
{
    vector<vector<string> > result;
    vector<string> output;
    dfs(s, 0, output, result);
    return result;
}

void dfs(string &s, int start, vector<string>& output, vector<vector<string> > &result)
{
    if(start == s.size()){
        result.push_back(output);
        return;
    }

    for(int i = start; i<s.size(); i++){
        if(isPalindrome(s, start, i)){
            output.push_back(s.substr(start, i-start+1));
            dfs(s, i+1, output, result);
            output.pop_back();
        }
    }
}

bool isPalindrome(string &s, int start, int end)
{
    while(start < end){
        if(s[start] != s[end]) return false;
        start++;
        end--;
    }
    return true;
}

