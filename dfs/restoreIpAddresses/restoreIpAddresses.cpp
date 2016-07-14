/*************************************************************************
	> File Name: restoreIpAddresses.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Thu 14 Jul 2016 07:32:57 PM HKT
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

vector<string> result;

//哈哈，这道题是我自己做出来的
void dfs(string s, int beg, int num, string ips)
{
    if(num == 3){
        if(beg == s.size()) return;
        string temp = s.substr(beg);
        if(temp.size() > 3) return;
        if(temp.size() > 1 && s[beg] == '0') return;
        int n = atoi(temp.c_str());
        if(n > 255) return;
        ips = ips + temp;
        result.push_back(ips);
    }
    if(num<3){
        if(s[beg] == '0'){
            ips = ips + "0.";
            dfs(s, beg+1, num+1, ips);
        }
        else{
        for(int i = 1; i<=3&&beg+i<s.size(); i++){
            string ipsbak = ips;
            string temp = s.substr(beg, i);
            int n = atoi(temp.c_str());
            if(n > 255) continue;
            ips = ips + temp + ".";
            dfs(s, beg+i, num+1, ips);
            ips = ipsbak;
        }
        }
    }
}

void  restoreIpAddresses(string s)
{
    result.clear();
    string ip = "";
    dfs(s, 0, 0, ip);
   // return result;
}

int main()
{
    string s;
    cin >> s;
    restoreIpAddresses(s);
    for(int i = 0; i<result.size(); i++){
        cout << result[i] << endl;
    }
}

