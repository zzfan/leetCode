/*************************************************************************
	> File Name: nextPermutation.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Mon 08 Aug 2016 10:15:36 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//这道题还是有点意思
void nextPermutation(vector<int> &nums)
{
    if(nums.size() < 2) return;
    int len = nums.size(), j = len-2;
    //找到递增序列
    while(j >= 0 && nums[j] >= nums[j+1]) j--;
    if(j<0){
        //如果是最大序列，则反转
        sort(nums.begin(), nums.end());
        return;
    }

    int i = j+1;
    //找到大于nums[j]的最小数字
    while(i<len && nums[i] > nums[j]) i++;
    i--;
    swap(nums[j], nums[i]);
    //j后面的排成最小
    sort(nums.begin()+j+1, nums.end());
}

