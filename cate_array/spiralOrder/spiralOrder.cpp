#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int min(int a, int b){
    return a>b?b:a;
}

vector<int> spiralOrder(vector<vector<int> > &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    vector<int> result;
    if(m == 0 || n == 0) return result;
    //因为不是方阵需要处理最后一列或一行
    int nVal = (min(m,n)+1)/2;
    for(int i = 0; i<nVal; i++){
        int lastRow = m-1-i;
        int lastCol = n-1-i;
        if(lastRow == i){
            //最后一行
            for(int j = i; j<=lastCol; j++){
                result.push_back(matrix[i][j]);
            }
        }
        else if(lastCol == i){
            //最后一列
            for(int j = i; j<=lastRow; j++){
                result.push_back(matrix[j][i]);
            }
        }
        else{
            for(int j = i; j<lastCol; j++){
                result.push_back(matrix[i][j]);
            }
            for(int j = i; j<lastRow; j++){
                result.push_back(matrix[j][lastCol]);
            }
            for(int j = lastCol; j>i; j--){
                result.push_back(matrix[lastRow][j]);
            }
            for(int j = lastRow; j>i; j--){
                result.push_back(matrix[j][i]);
            }
        }
    }
    return result;
}
