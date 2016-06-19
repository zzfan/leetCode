/*************************************************************************
	> File Name: containsDuplicate.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Sun 19 Jun 2016 04:33:48 PM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool containsDuplicate(vector<int>& nums)
{
    set<int> s;
    for(int i = 0; i<nums.size(); i++){
        if(s.find(nums[i]) == s.end()) 
            s.insert(nums[i]);
        else
            return true;
    }
    return false;
}

