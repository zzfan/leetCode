/*************************************************************************
	> File Name: solveNQueens.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Thu 14 Jul 2016 03:35:13 PM HKT
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int row[1000];
int col[1000];
vector<vector<string> > result;

void dfs(int r, int n)
{
    if(r == n){
        vector<string> temp;
        for(int i = 0; i<n; i++){
            string s(n, '.');
            s[row[i]] = 'Q';
            temp.push_back(s);
        }
        result.push_back(temp);
    }

    int i,j;
    for(i = 0; i<n; i++){
        if(col[i] == 0){
            for(j = 0; j<r; j++){
                if(abs(j-r) == abs(row[j] - i)) break;
            }
            if(j == r){
                row[r] = i;
                col[i] = 1;
                dfs(r+1, n);
                row[r] = 0;
                col[i] = 0;
            }
        }
    }
}

vector<vector<string> > solveNQueens(int n)
{
    result.clear();
    dfs(0, n);
    return result;
}
