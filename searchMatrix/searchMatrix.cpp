/*************************************************************************
	> File Name: searchMatrix.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Thu 21 Apr 2016 09:02:05 PM HKT
 ************************************************************************/

#include<iostream>
#include <vector>
using namespace std;
//二维矩阵的二分查找算法

bool searchMatrix(vector<vector<int> >& matrix, int target)
{
    int size = matrix.size();
    if(size == 0){
        return false;
    }
    int rows = matrix.size();
    int cols = matrix[0].size();
    int first = 0, last = matrix.size()*matrix[0].size()-1;
    while(first < last){
        int middle = first + (last - first)/2;
        int mvalue = matrix[middle/cols][middle%cols];
        if(mvalue == target) return true;
        if(mvalue > target) last = middle - 1;
        else first = middle + 1;
    }
    return false;
}

