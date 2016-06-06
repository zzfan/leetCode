/*************************************************************************
	> File Name: lengthOfLongestSubstring.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Thu 24 Mar 2016 12:38:29 AM PDT
 ************************************************************************/

#include<iostream>
#include <string>
#include <cstring>
using namespace std;

int lengthOfLongestSubstring(string s){
    //暴力解法，效率非常的低，当然在leetcode上也没有通过
    int offset,k=0;
    string temp;
    int length, pre_length = 0;
    for(int i=0; i<s.size(); i++){
        offset = i;
        length = 1;
        for(int j=i+1; j<s.size(); j++){
            for( k = offset; k<j; k++){
                if (s[k] == s[j])
                    break;
            }
            if(j==k) length++;
        }
        if(length > pre_length)
            pre_length = length;
    }
    return pre_length;
}

int lengthOfLongestSubstring_new(string s){
    //left用以记录合法的最远左边界位置，last记录字符上一次出现的位置
    int ans = 0, left = 0, len = s.size();
    int last[256];
    if(len == 0)
        return 0;
    //一定要注意memset是针对每个字节的，所以不需要除以sizeof(last[0])
    memset(last, -1, sizeof(last));
    
    for (int i = 0; i<len; i++){
        if (last[s[i]] >= left) left = last[s[i]] + 1;
        last[s[i]] = i;
        if(i-left+1 > ans)
            ans = i-left+1;
    }
    return ans;
}

 int lengthOfLongestSubstring_test(string s) {
        int hash[256];
        for(int i=0; i<256; i++) hash[i] = -1;
        int start = 0, ans = 0;
        int i;
        for(i=0; i<s.size(); i++){
            if( -1 != hash[ s[i] ] ){
                if(ans < i-start) ans = i-start;
                for(int j=start; j<hash[ s[i] ]; j++) hash[j] = -1;
                if(hash[  s[i] ] + 1  > start )
                    start = hash[ s[i] ] +1;
            }
            hash[ s[i]] = i;
        }
        if(ans < i-start) ans = i-start;
        return ans;
    }


int main()
{
    string s;
    cin >> s;
    cout << "power method: " << lengthOfLongestSubstring(s) << endl;
    cout << "ASCII method: " << lengthOfLongestSubstring_new(s) << endl;
    cout << "test: " << lengthOfLongestSubstring_test(s) << endl;
}
