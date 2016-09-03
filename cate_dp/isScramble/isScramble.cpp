/*************************************************************************
	> File Name: isScramble.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Sat 03 Sep 2016 07:45:09 PM HKT
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isScramble(string s1, string s2)
{
    if(s1.size() != s2.size()) return false;
    vector<int> m(26, 0);
    for(int i = 0; i<s1.size(); i++){
        m[s1[i]-'a']++;
    }
    for(int i = 0; i<s2.size(); i++){
        m[s2[i]-'a']--;
    }
    for(int i = 0; i<26; i++){
        if(m[i] != 0)
            return false;
    }
    if(s1.size() == 1 && s2.size() == 1) return true;

    for(int i = 1; i<s1.size(); i++){
        bool res = isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, s1.size()-i), s2.substr(i, s1.size()-i));
        res = res || (isScramble(s1.substr(0, i), s2.substr(i, s2.size()-i)) && isScramble(s1.substr(i, s1.size()-i), s2.substr(0, s1.size()-i)));
        if(res) return true;
    }
    return false;
}

