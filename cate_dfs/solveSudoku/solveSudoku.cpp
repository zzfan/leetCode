/*************************************************************************
	> File Name: solveSudoku.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Fri 15 Jul 2016 12:43:57 PM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<vector<char> > &board, int row, int col)
{
    for(int i = 0; i<9; i++){
        if(i != col && board[row][i] == board[row][col])
            return false;
        if(i != row && board[i][col] == board[row][col])
            return false;
    }
    int m = row/3, n = col/3;
    for(int i = m*3; i<m*3+3; i++){
        for(int j = n*3; j<n*3+3; j++){
            if(i != row && j != col && board[i][j] == board[row][col])
            return false;
        }
    }
    return true;
}

bool dfs(vector<vector<char> > &board, int irow, int icol)
{
    if(irow == 9) return true;
    int trow, tcol;
    if(icol == 8){
        trow = irow + 1;
        tcol = 0;
    }else{
        trow = irow;
        tcol = icol + 1;
    }

    if(board[irow][icol] != '.'){
        if(!isValid(board, irow, icol)) return false;
        return dfs(board, trow, tcol);
    }

    for(int i = 1; i<=9; i++){
        board[irow][icol] = '0' + i;
        if(isValid(board, irow, icol) && dfs(board, trow, tcol)) return true;
    }

    board[irow][icol] = '.';
    return false;
}

void solveSudoku(vector<vector<char> > &board)
{
    dfs(board, 0, 0);
}

