/*************************************************************************
	> File Name: groupAnagrams.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Wed 06 Jul 2016 12:01:45 PM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

string getSort(string s)
{
    sort(s.begin(), s.end());
    return s;
}

vector<vector<string> > groupAnagrams(vector<string>& strs)
{
    vector<vector<string> > result;
    map<string, vector<string> > strmap;

    for(int i = 0; i<strs.size(); i++){
        strmap[getSort(strs[i])].push_back(strs[i]);
    }
    for(map<string, vector<string> >::iterator it = strmap.begin(); it != strmap.end(); it++){
        result.push_back(it->second);
    }
    return result;
}


