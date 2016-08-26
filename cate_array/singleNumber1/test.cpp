/*************************************************************************
	> File Name: test.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Thu 25 Aug 2016 10:34:26 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int> &nums)
{
    vector<int> flag(32, 0);
    for(int i = 0; i<nums.size(); i++){
        int offset = 1;
        int temp = nums[i];
        for(int k = 0; k<32; k++){
            if(temp&(offset<<k)) flag[k]++;
        }
    }
    int res = 0;
    for(int i = 31; i>=0; i--){
        if(flag[i]%3==1)
            res = res*2 + 1;
        else
            res = res*2;
    }
    return res;
}

int main()
{
    vector<int> nums = {2, 2, 9, 2};
    int res = singleNumber(nums);
    cout << res << endl;
}

