/*************************************************************************
	> File Name: titleToNumber.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Fri 29 Apr 2016 08:46:24 AM HKT
 ************************************************************************/

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int titleToNumber(string s)
{
    if(s.size() == 0) return 0;
    if(s.size() == 1) return s[0]-'A'+1;
    int result = 0, flag = 0;
    for(int i = s.size()-1; i >= 0; i--){
        result += pow(26, flag)*(s[i] - 'A' + 1);
        flag++;
    }
    return result;
}

int main()
{
    string s;
    while(cin >> s){
        cout << titleToNumber(s) << endl;
    }
    return 0;
}
