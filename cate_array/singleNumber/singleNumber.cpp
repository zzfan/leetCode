/*************************************************************************
	> File Name: singleNumber.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Thu 25 Aug 2016 10:01:35 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int res = nums[0];
    for(int i = 1; i<nums.size(); i++)
        res = res^nums[i];
    return res;
}

