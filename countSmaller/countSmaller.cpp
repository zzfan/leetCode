/*************************************************************************
	> File Name: countSmaller.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Sun 08 May 2016 12:37:30 PM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

vector<int> countSmaller(vector<int>& nums)
{
    vector<int> t, res(nums.size());
    for(int i = nums.size()-1; i >= 0; --i){
        int left = 0, right = t.size();
        while(left < right){
            int mid = left + (right - left)/2;
            if (t[mid] >= nums[i]) right = mid;
            else left = mid + 1;
        }
        res[i] = right;
        t.insert(t.begin() + right, nums[i]);
    }
    return res;
}

vector<int> countSmaller1(vector<int>& nums)
{
    vector<int> t, res(nums.size());
    for(int i = nums.size() - 1; i >= 0; --i){
        int d = distance(t.begin(), lower_bound(t.begin(), t.end(), nums[i]));
        res[i] = d;
        t.insert(t.begin() + d, nums[i]);
    }
    return res;
}

int main()
{
    vector<int> nums = {5, 2, 6, 1};
    vector<int> res = countSmaller(nums);
    for(int i = 0; i<res.size(); i++){
        cout << res[i] << ' ';
    }
    cout << endl;
}




