/*************************************************************************
	> File Name: singleNumber.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Thu 25 Aug 2016 10:06:31 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int> &nums) {
       int res = 0;
       int n = nums.size();
       for(int i=31; i>=0; i--) {
           int sum = 0;
           int mask = 1<<i;
           for(int j=0; j<n; j++) {
               if(nums[j] & mask) 
                   sum++;
           }
           res = (res<<1) + (sum%3);
       }
       return res;
   }

int main()
{
    vector<int> nums = {2, 2, 3, 2};
    int res = singleNumber(nums);
    cout << res << endl;
}

