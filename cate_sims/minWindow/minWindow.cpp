/*************************************************************************
	> File Name: minWindow.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Tue 19 Jul 2016 07:28:28 PM HKT
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

//暴力解法
string minWindow_force(string s, string t)
{
    if(s.size() < t.size()) return "";
    if(t.size() == 0) return "";
    int tlen = t.size();
    int srcCnt[256] = {0};
    int foundCnt[256] = {0};
    for(int i = 0; i<t.size(); i++){
        srcCnt[t[i]]++;
    }
    int hasFound;
    int min = s.size(); 
    string result;
    for(int i = 0; i<s.size(); i++){
        if(t.find(s[i], 0) == string::npos) continue; 
        hasFound = 0;
        for(int j = i; j<s.size(); j++){
            if(srcCnt[s[j]] != 0){
                if(foundCnt[s[j]] < srcCnt[s[j]]){
                    foundCnt[s[j]]++;
                    hasFound++;
                }
                if(hasFound == tlen){
                    if(j-i+1 < min){
                        result.clear();
                        min = j-i+1;
                        result = s.substr(i, min);
                    }
                    break;
                }
            }
        }
    }
    return result;
}

int main()
{
    string s,t;
    cin >> s >> t;
    cout << minWindow_force(s, t);
}

