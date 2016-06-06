/*************************************************************************
	> File Name: generateParenthesis.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Wed 06 Apr 2016 03:26:42 PM HKT
 ************************************************************************/

#include<iostream>
#include <string>
#include <vector>
using namespace std;

void helper(string s, vector<string> res, int l, int r)
{
    if(r<1){
        return;
    }
    if(l == 0 && r == 0){
        res.push_back(s);
    }
    if(l>0)
    helper(s+"(", res, l-1, r);
    if(r>0)
    helper(s+")", res, l, r-1);
}

vector<string> generateParentesis(int n)
{
    string s;
    vector<string> res;
    helper(s, res, n, n);
    return res;
}

int main()
{
    int n;
    vector<string> result;
    while(cin >> n){
        result = generateParentesis(n);
        for(int i = 0; i<result.size(); i++){
            cout << result[i] << endl;
        }
    }
    return 0;
}

