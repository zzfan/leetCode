/*************************************************************************
	> File Name: checkSudoku.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Sat 16 Apr 2016 11:19:53 AM HKT
 ************************************************************************/

#include<iostream>
#include <vector>
#include <cstring>
#include <sstream>
using namespace std;

bool check(char c, bool exist[9])
{
    if(c == '.') return true;
    if(exist[c-'1'] == true) return false;
    exist[c-'1'] = true;
    return true;
}

bool isValidSudoku(vector<vector<char> >& board)
{
    bool exist[9];
    memset(exist, false, sizeof(exist));
    for(int i = 0; i<9; i++){
        memset(exist, false, sizeof(exist));
        for(int j = 0; j<9; j++){
            if(!check(board[i][j], exist))
            return false;
        }
        memset(exist, false, sizeof(exist));
        for(int j = 0; j<9; j++){
            if(!check(board[j][i], exist))
            return false;
        }

        for(int m = 0; m<3; m++)
        for(int n = 0; n<3; n++){
            memset(exist, false, sizeof(exist));
            for(int p = 3*m; p < 3*m+3; p++)
            for(int q = 3*n; q < 3*n+3; q++){
                if(!check(board[p][q], exist))
                return false;
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<char> > board;
    char tag;
    string str;
    for(int j = 0; j<9; j++)
    {
        getline(cin, str);
        stringstream sp(str);
        vector<char> temp;
        temp.clear();
        for(int i = 0; i<9; i++){
            sp >> tag;
            temp.push_back(tag);
        }
        board.push_back(temp);
    }
    cout << isValidSudoku(board) << endl;
    return 0;
}
