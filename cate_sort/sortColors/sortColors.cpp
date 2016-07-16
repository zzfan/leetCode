/*************************************************************************
	> File Name: sortColors.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Sat 16 Jul 2016 04:51:54 PM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

//这题技巧感觉还可以，一下子可能想不出来
//就是把０往前放，把２往后放
void sortColors(vector<int>& nums)
{
    int left = 0, right = nums.size()-1;
    int i = 0;
    while(i<=right){
        if(nums[i] == 0){
            swap(nums[left++], nums[i++]);
        }
        else if(nums[i] == 1)
            i++;
        else if(nums[i] == 2){
            swap(nums[i], nums[right--]);
        }
    }
}

