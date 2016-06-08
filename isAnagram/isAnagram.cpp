/*************************************************************************
	> File Name: isAnagram.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Wed 08 Jun 2016 09:20:29 AM HKT
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

//排序后判别相等
bool isAnagram(string s, string t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s==t;
}

//计数判相等
bool isAnagram1(string s, string t)
{
    vector<int> count(26, 0);
    for(int i = 0; i<s.size(); i++)
        count[s[i]-'a']++;
    for(int i = 0; i<t.size(); i++)
        count[t[i]-'a']--;
    for(int i = 0; i<26; i++)
        if(count[i] != 0) return false;
    return true;
}

