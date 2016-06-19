/*************************************************************************
	> File Name: containsNearbyDuplicate.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Sun 19 Jun 2016 04:49:59 PM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k)
{
    unordered_map<int, int> m;
    for(int i = 0; i<nums.size(); i++){
        if(m.find(nums[i]) != m.end() && i-m[nums[i]] <= k) return true;
        else m[nums[i]] = i;
    }
    return false;
}

