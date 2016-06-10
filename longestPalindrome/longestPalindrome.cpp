/*************************************************************************
	> File Name: longestPalindrome.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Fri 10 Jun 2016 12:09:18 PM HKT
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

string longestPalindrome(string s) {
    int max,c,offset = 0;
    string sub;
    int len = s.size();
    if(len < 1) return 0;
    max = 1;
    
    for(int i = 0; i<len; i++){
        //偶数情况
        for(int j = 0; i-j>=0&&i+j+1<len; j++){
            if(s[i-j] != s[i+j+1]) break;
            c = 2*j + 2;
            if(c>max){
                max = c;
                offset = i-j;
                sub = s.substr(offset, max);
            }
        }
        
        //奇数情况
        for(int j = 0; i-j>=0&&i+j<len; j++){
            if(s[i-j] != s[i+j]) break;
            c = 2*j + 1;
            if(c>max){
                max = c;
                offset = i-j;
                sub = s.substr(offset, max);
            }
        }
    }
    return sub;
}

int main()
{
    string s;
    while(cin >> s){
        cout << longestPalindrome(s) << endl;
    }
}






