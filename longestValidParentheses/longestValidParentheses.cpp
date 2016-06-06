/*************************************************************************
	> File Name: longestValidParentheses.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Wed 11 May 2016 09:15:55 AM HKT
 ************************************************************************/

#include <iostream>
#include <stack>
#include <string>
#include <cstring>
using namespace std;

int longestValidParentheses(string s)
{
    bool *flag = new bool[s.size()];
    memset(flag, false, s.size());
    stack<int> st;

    for(int i = 0; i<s.size(); i++){
        if(s[i] == '(')
            st.push(i);
           else if(!st.empty()){
               flag[i] = true;
               flag[st.top()] = true;
               st.pop();
           }
    }
    int max_len = 0, cur_len = 0;
    for(int i = 0; i<s.size(); i++){
        if(flag[i]) ++cur_len;
        else cur_len = 0;
        if(cur_len > max_len) 
             max_len = cur_len;
    }
    return max_len;
}

int main()
{
    string s = "(((())))";
    cout << longestValidParentheses(s) << endl;
}

