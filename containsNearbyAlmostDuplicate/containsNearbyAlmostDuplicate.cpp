/*************************************************************************
	> File Name: containsNearbyAlmostDuplicate.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Sun 19 Jun 2016 03:43:17 PM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<int, int> m;
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i - j > k) m.erase(nums[j++]);
            auto a = m.lower_bound(nums[i] - t);
            if (a != m.end() && abs(a->first - nums[i]) <= t) return true;
            m[nums[i]] = i;
        }
        return false;
    }



