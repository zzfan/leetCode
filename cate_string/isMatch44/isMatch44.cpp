/*************************************************************************
	> File Name: isMatch44.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Mon 04 Jul 2016 05:29:27 PM HKT
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

//和第10题一样的
//递归版本
//timeout
bool cIsMatch1(const char* s, const char* p)
{
    if(*p == '*'){
        while(*p == '*') ++p;
        if(*p == '\0') return true;
        while(*s != '\0' && !cIsMatch1(s, p)) ++s;
        return *s != '\0';
    }
    else if(*p == '\0' || *s == '\0') return *p == *s;
    else if(*p == *s || *p == '?') return cIsMatch1(++s, ++p);
    else return false;
}

//迭代版本，没有超时
bool cIsMatch(const char* s, const char* p)
{
    bool star = false;
    const char *str, *ptr;
    for(str = s, ptr = p; *str != '0'; str++, ptr++){
        switch(*ptr){
            case '?':
            break;

            case '*':
            star = true;
            s = str, p = ptr;
            while(*p == '*') p++;
            if(*p == '0') return true;
            str = s-1;
            ptr = p-1;
            break;

            default:
            if(*str != *ptr){
                if(!star) return false;
                s++;
                str = s-1;
                ptr = p-1;
            }
        }    
    }
    while(*ptr == '*') ptr++;
    return (*ptr == '\0');
}


bool isMatch1(string s, string p)
{
    return cIsMatch(s.c_str(), p.c_str());
}

bool isMatch(string s, string p) {
        if (s.length() == 0 && p.length() == 0) return true;
        bool dp[p.length()];
        bool placeHolder = true;
        // init the dp value when the s is empty
        for (int i = 0; i < p.length(); i ++) {
            if (p[i] == '*') dp[i] = placeHolder;
            else dp[i] = false, placeHolder = false;
        }
        
        for (int i = 0; i < s.length(); i ++) {
            // first calculate the dp value reversely
            for (int j = p.length() - 1; j > 0; j --) {
                if (p[j] == '*') dp[j] = dp[j - 1] || dp[j];
                else if (p[j] == '?') dp[j] = dp[j - 1];
                else dp[j] = dp[j - 1] && s[i] == p[j];
            }
            if (i == 0) dp[0] = p[0] == s[0] || p[0] == '?' || p[0] == '*';
            else if (p[0] != '*') dp[0] = false;
            else dp[0] = true;
            // add the value missed when using reverse calculation
            for (int j = 1; j < p.length(); j ++) {
                if (p[j] == '*') dp[j] = dp[j - 1] || dp[j];
            }
        }
        
        return dp[p.length() - 1];
    }

int main()
{
    string s,p;
    while(cin >> s >> p){
        cout << isMatch(s,p) << endl;
    }
}

