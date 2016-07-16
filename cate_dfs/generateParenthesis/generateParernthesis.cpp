/*************************************************************************
	> File Name: generateParernthesis.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Fri 15 Jul 2016 12:04:13 PM HKT
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> result;
//有提示还好点，注意判断条件
void dfs(int n, int start, string &sol, int lnum, int rnum)
{
    if(lnum == n && rnum == n){
        result.push_back(sol);
        return;
    }
    if(lnum < n){
        sol = sol + "(";
        dfs(n, start+1, sol, lnum+1, rnum);
        sol.erase(sol.size()-1);
    }
    if(rnum < lnum && rnum < n){
        sol = sol + ")";
        dfs(n, start+1, sol, lnum, rnum+1);
        sol.erase(sol.size()-1);
    }
}

vector<string> generateParenthesis(int n)
{
    result.clear();
    string sol;
    dfs(n, 0, sol, 0, 0);
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<string> temp = generateParenthesis(n);
    for(int i = 0; i<temp.size(); i++){
        cout << temp[i] << endl;
    }
}

