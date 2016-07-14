/*************************************************************************
	> File Name: totalNQueens.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Thu 14 Jul 2016 04:24:45 PM HKT
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int row[1000];
int col[1000];
//刚开始用count,发现是关键字
int num;

void dfs(int r, int n)
{
    int i,j;
    if(r == n){
        num++;
    }
    for(i = 0; i<n; i++){
        if(col[i] == 0){
            for(j = 0; j<r; j++){
                if(abs(j-r) == abs(row[j]-i)) break;
            }
            if(j==r){
                row[r] = i;
                col[i] = 1;
                dfs(r+1, n);
                row[r] = 0;
                col[i] = 0;
            }
        }
    }
}

int totalNQueens(int n)
{
    num = 0;
    dfs(0, n);
    return num;
}

