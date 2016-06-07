/*************************************************************************
	> File Name: increasingTriplet.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Tue 07 Jun 2016 09:53:52 AM HKT
 ************************************************************************/

#include <iostream>
#include <vector>

#define INT_MAX 0x7fffffff
#define INT_MIN 0x80000000

using namespace std;

//维护一个dp数组，dp[i]表示在i位置之前小于nums[i]的数字的个数
//初始化为1，我们遍历其之前的所有数字，如果之前某个数字nums[j]小于nums[i]，那么我们更新dp[i] = max(dp[i], dp[j] + 1)
//这个方法时间复杂度和空间复杂度都超了
bool increasingTriplet1(vector<int>& nums)
{
    vector<int> dp(nums.size(), 1);
    for(int i = 0; i<nums.size(); ++i){
        for(int j = 0; j<i; ++j){
            if(nums[j] < nums[i]){
                dp[i] = max(dp[i], dp[j]+1);
                if(dp[i] >= 3) return true;
            }
        }
    }
    return false;
}

//维护一个最小值和倒数第二小的值
bool increasingTriplet(vector<int>& nums)
{
    int m1 = INT_MAX, m2 = INT_MAX;
    for(int i = 0; i<nums.size(); i++){
        if(m1 >= nums[i]) m1 = nums[i];
        else if(m2 >= nums[i]) m2 = nums[i];
        else return true;
    }
    return false;
}

int main()
{
    vector<int> nums = {5, 3, 2, 4, 1};
    cout << increasingTriplet(nums) << endl;
}
