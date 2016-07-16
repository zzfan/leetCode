/*************************************************************************
	> File Name: exist.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Fri 15 Jul 2016 02:31:51 PM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool dfs(vector<vector<char> > &board, string word, int start, int row, int col, vector<vector<bool> > &flag)
{
    if(start == word.size()-1) return true;
    flag[row][col] = false;
    if(row<board.size()-1 && flag[row+1][col] && board[row+1][col] == word[start+1]){
        if(dfs(board, word, start+1, row+1, col, flag)) return true;
    }
    if(row>0 && flag[row-1][col] && board[row-1][col] == word[start+1]){
        if(dfs(board, word, start+1, row-1, col, flag)) return true;
    }
    if(col<board[row].size()-1 && flag[row][col+1] && board[row][col+1] == word[start+1]){
        if(dfs(board, word, start+1, row, col+1, flag)) return true;
    }
    if(col>0 && flag[row][col-1] && board[row][col-1] == word[start+1]){
        if(dfs(board, word, start+1, row, col-1, flag)) return true;
    }
    flag[row][col] = true;
    return false;
}

bool exist(vector<vector<char> > &board, string word)
{
    int row = board.size(), col = board[0].size();
    vector<vector<bool> > flag(row, vector<bool>(col, true));
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            if(board[i][j] == word[0] && dfs(board, word, 0, i, j, flag)){
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<char> > board(m,vector<char>(n));
    string word;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cin >> board[i][j];
        }
    }
    cin >> word;
    cout << exist(board, word) << endl;
}
