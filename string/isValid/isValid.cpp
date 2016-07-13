/*************************************************************************
	> File Name: isValid.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Mon 04 Apr 2016 02:41:47 PM HKT
 ************************************************************************/

#include<iostream>
#include<stack>
#include<map>
#include<string>
using namespace std;

bool isValid(string s)
{
    stack<char> temp;
    for(int i = 0; i<s.size(); i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            temp.push(s[i]);
        }
        else{
            if(temp.empty()) return false;
            if(s[i] == ')' && temp.top() != '(')
            return false;
            if(s[i] == ']' && temp.top() != '[')
            return false;
            if(s[i] == '}' && temp.top() != '{')
            return false;
            temp.pop();
        }
    }
    if(temp.empty()){
        return true;
    }
    else
        return false;
}

int main()
{
    string s;
    while(cin >> s){
        cout << isValid(s) << endl;
    }
    return 0;
}
