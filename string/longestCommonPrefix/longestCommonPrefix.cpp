/*************************************************************************
	> File Name: longestCommonPrefix.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Sun 19 Jun 2016 01:01:40 PM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs)
{
    if(strs.size() == 0) return "";
    string prefix = strs[0];
    for(int i = 1; i<strs.size(); i++){
        if(strs[i].size() == 0) return "";
        int len = prefix.size() > strs[i].size() ? prefix.size():strs[i].size();
        int j = 0;
        for(j = 0; j<len; j++){
            if(prefix[j] != strs[i][j])
            break;
        }
        prefix = prefix.substr(0,j);
    }
    return prefix;
}

int main()
{
    vector<string> strs = {"abcd", "abc", "abcf"};
    cout << longestCommonPrefix(strs) << endl;
}
