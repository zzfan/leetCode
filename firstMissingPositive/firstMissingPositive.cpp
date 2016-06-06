/*************************************************************************
	> File Name: firstMissingPositive.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Sat 07 May 2016 09:26:42 AM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

//这题的关键是找出第一个miss的正数，也就是说数值可以和下标对应了
//要求的是常数空间
int firstMissingPositive(vector<int>& nums)
{
    int n = nums.size();
    int i = 0;
    while(i < n){
        if(nums[i] != i+1 && nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i]-1]){
            int temp = nums[i];
            nums[i] = nums[temp-1];
            nums[temp-1] = temp;
        }
        else i++;
    }
    for(i = 0; i<n; i++){
        if(nums[i] != i+1) return i+1;
    }
    return n+1;
}

int firstMissingPositive1(vector<int>& nums)
{
    set<int> temp;
    int n = nums.size();
    for(int i = 0; i<n; i++){
        if(nums[i] > 0)
        temp.insert(nums[i]);
    }
    for(int m=1; ;m++){
        if(!temp.count(m))
        return m;
    }
}

int main()
{
    vector<int> nums = {-1, 2, 1, 3, 5};
    cout << firstMissingPositive(nums) << endl;
    cout << firstMissingPositive1(nums) << endl;
    return 0;
}

