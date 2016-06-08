/*************************************************************************
	> File Name: maxProduct.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Tue 07 Jun 2016 11:22:53 AM HKT
 ************************************************************************/

#include <iostream>
#include <vector>

#define INT_MIN 0x80000000
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))

using namespace std;

//暴力解法，枚举法
int maxProduct1(vector<int>& nums)
{
    int max = INT_MIN;
    for(int i = 0; i<nums.size(); i++){
        int temp = 1;
        for(int j = i; j<nums.size(); j++){
            temp *= nums[j];
            if(temp > max) max = temp;
        }
    }
    return max;
}

//维护一个最大最小值
int maxProduct(vector<int>& nums)
{
    if(nums.size() < 1) return 0;
    int maxProduct = nums[0];
    int max_temp = nums[0];
    int min_temp = nums[0];

    for(int i = 1; i<nums.size(); i++){
        int a = nums[i]*max_temp;
        int b = nums[i]*min_temp;
        max_temp = max(max(a,b), nums[i]);
        min_temp = min(min(a,b), nums[i]);
        maxProduct = max(maxProduct, max_temp);
    }
    return maxProduct;
}

