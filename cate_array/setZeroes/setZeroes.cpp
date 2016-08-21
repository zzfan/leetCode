/*************************************************************************
	> File Name: setZeroes.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Sun 21 Aug 2016 04:30:27 PM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void setRowCol(vector<vector<int> > &matrix, int num, bool flag)
{
    if(flag == true){
        for(int i = 0; i<matrix[0].size(); i++)
            matrix[num][i] = 0;
    }
    else{
        for(int i = 0; i<matrix.size(); i++)
            matrix[i][num] = 0;
    }
}

void setZeroes(vector<vector<int> > &matrix)
{
    if(matrix.empty() || matrix[0].empty()) return;
    int zeroColFlag = 1, zeroRowFlag = 1;
    int row = matrix.size(), col = matrix[0].size();

    for(int i = 0; i<col; i++){
        if(matrix[0][i] == 0){
            zeroRowFlag = 0;
            break;
        }
    }
    for(int i = 0; i<row; i++){
        if(matrix[i][0] == 0){
            zeroColFlag = 0;
            break;
        }
    }
    for(int i = 1; i<row; i++){
        for(int j = 1; j<col; j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for(int i = 1; i<row; i++)
        if(matrix[i][0] == 0)
            setRowCol(matrix, i, true);
    for(int i = 1; i<col; i++){
        if(matrix[0][i] == 0)
            setRowCol(matrix, i, false);
    }
    if(zeroRowFlag == 0) setRowCol(matrix, 0, true);
    if(zeroColFlag == 0) setRowCol(matrix, 0, false);
}

int main()
{
    vector<vector<int> > matrix = {{0,2}};
    setZeroes(matrix);
    for(int i = 0; i<matrix.size(); i++){
        for(int j = 0; j<matrix[0].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

