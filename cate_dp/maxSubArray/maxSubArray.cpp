/*************************************************************************
	> File Name: maxSubArray.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Fri 26 Aug 2016 02:55:14 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//找出数组中连续的最大和
int maxSubArray(vector<int> &nums)
{
    int len = nums.size();
    if(len <= 0) return 0;
    int maxSum = nums[0], curSum = nums[0];
    for(int i = 1; i<len; i++){
        curSum = curSum<=0 ? nums[i] : curSum+nums[i];
        maxSum = max(maxSum, curSum);
    }
    return maxSum;
}

