/*************************************************************************
	> File Name: isMatch.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Sun 03 Jul 2016 09:55:05 PM HKT
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

//10.Regular Expression Matching
//递归方法
bool cIsMatch(const char* s, const char* p)
{
    if(*p == 0 && *s == 0) return true;
    
    if(*p != 0){
        if(*(p+1) != '*'){
            if((*s == *p) || (*p == '.' && *s != 0))
            return cIsMatch(s+1, p+1);
            return false;
        }
        else{
            if(cIsMatch(s, p+2)) return true;
            for(int i = 0; *(s+i) != 0; i++){
                if(*p != '.' && *(s+i) != *p)
                break;
                if(cIsMatch(s+i+1, p+2))
                return true;
            }
        }
    }
    return false;
}

bool isMatch(string s, string p)
{
    return cIsMatch(s.c_str(), p.c_str());
}

int main()
{
    string s, p;
    while(cin >> s >> p){
        cout << isMatch(s, p) << endl;
    }
}

