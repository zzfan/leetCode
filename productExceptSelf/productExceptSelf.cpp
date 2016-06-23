/*************************************************************************
	> File Name: productExceptSelf.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Tue 21 Jun 2016 11:04:01 AM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

//没有考虑０的情况，０的情况这种方法比较复杂
vector<int> productExceptSelf1(vector<int>& nums)
{
    long long temp = 1;
    vector<int> result;
    for(int i = 0; i<nums.size(); i++){
        temp *= nums[i];
    }
    for(int i = 0; i<nums.size(); i++){
        result.push_back(temp/nums[i]);
    }
    return result;
}

vector<int> productExceptSelf(vector<int>& nums)
{
    vector<int> result;
    if(nums.size() == 0) return result;
    int product = 1; 

    result.push_back(1);
    for(int i = 0; i<nums.size()-1; i++){
        product *= nums[i];
        result.push_back(product);
    }

    product = 1;
    for(int i = nums.size()-1; i>=0; i--){
        product *= nums[i];
        result[i-1] *= product;
    }
    return result;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result;
    result = productExceptSelf(nums);
    for(int i = 0; i<result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
}

