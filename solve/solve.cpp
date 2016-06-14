/*************************************************************************
	> File Name: solve.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Sat 11 Jun 2016 09:36:04 PM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

//刚开始把这题想的有点难了
//其实先把边界的o找出来，然后剩下的都变为x就行

void dfs(vector<vector<char> > &board, int i, int j)
{
    if(i > board.size()-1 || i<0 || j>board[0].size()-1 || j<0)
    return;

    if(board[i][j] == 'O'){
        board[i][j] = 'C';
        dfs(board, i+1, j);
        dfs(board, i-1, j);
        dfs(board, i, j+1);
        dfs(board, i, j-1);
    }
}

void solve(vector<vector<char> >& board)
{
    int row = board.size();
    int col = board[0].size();
    if(row == 0) return;

    for(int i = 0; i<row; i++){
        dfs(board, i, 0);
        dfs(board, i, col-1);
    }

    for(int j = 0; j<col; j++){
        dfs(board, 0, j);
        dfs(board, row-1, j);
    }
    
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            if(board[i][j] == 'O') board[i][j] = 'X';
            if(board[i][j] == 'C') board[i][j] = 'O';
        }
    }
}

int main()
{
    int m,n;
    while(cin >> m >> n){
        vector<vector<char> > board;
        cin.get();
        for(int i = 0; i<m; i++){
            vector<char> temp;
            string s;
            getline(cin, s);
            stringstream sp(s);
            for(int j = 0; j<n; j++){
                char c;
                sp >> c;
                temp.push_back(c);
            }
            board.push_back(temp);
        }
        solve(board);
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){
                cout <<  board[i][j] << ' ';
            }
            cout << endl;
        }
    }
}




