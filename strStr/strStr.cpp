/*************************************************************************
	> File Name: strStr.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Fri 15 Apr 2016 09:35:53 AM HKT
 ************************************************************************/

#include<iostream>
#include <string>
using namespace std;

int strStr(string haystack, string needle)
{
    int len = needle.size();
    if(len > haystack.size())
    return -1;
    if(len <= 0)
    return 0;
    for(int i = 0; i<haystack.size(); i++){
        if(needle[0] == haystack[i] && needle[len-1] == haystack[i+len-1]){
            int m = 0;
            for(int j = i; m<len; j++,m++){
                if(needle[m] != haystack[j])
                break;
            }
            if(m == len)
            return i;
        }
    }
    return -1;
}

int main()
{
    string  haystack, needle;
    while(cin >> haystack >> needle){
        cout << strStr(haystack, needle) << endl;
    }
    return 0;
}
