/*************************************************************************
	> File Name: plusOne.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Sun 21 Aug 2016 03:00:51 PM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

vector<int> plusOne(vector<int>& digits)
{
    int len = digits.size();
    int flag = 0;
    digits[len-1] += 1;
    for(int i = len-1; i>=0; i--){
        digits[i] += flag;
        if(digits[i] >= 10){
            digits[i] = digits[i] - 10;
            flag = 1;
        }
        else
            flag = 0;
    }
    if(flag == 1){
        vector<int> res(len+1, 0);
        res[0] = 1;
        return res;
    }
    return digits;
}

