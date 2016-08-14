/*************************************************************************
	> File Name: fourSum.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Mon 08 Aug 2016 08:33:26 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void twoSum(vector<int> &num, int start, int end, int target, vector<int> &sol, vector<vector<int> > &allSol) {
        while(start<end) {
            int sum = num[start]+num[end];
            if(sum==target) {
                sol.push_back(num[start]);
                sol.push_back(num[end]);
                allSol.push_back(sol);
                sol.pop_back();
                sol.pop_back();
                start++;
                end--;
                while(num[start]==num[start-1]) start++;
                while(num[end]==num[end+1]) end--;
            }
            else if(sum<target)
                start++;
            else
                end--;
        }
    }

void kSum(vector<int> &nums, int start, int end, int target, int k, vector<int> &sol, vector<vector<int> > &res)
{
    if(k<=0) return;
    if(k==1){
        for(int i = start; i<=end; i++){
            if(nums[i] == target){
                sol.push_back(target);
                res.push_back(sol);
                sol.pop_back();
                return;
            }
        }
    }
    if(k==2){
        twoSum(nums, start, end, target, sol, res);
        return;
    }
    for(int i = start; i<=end-k+1; i++){
        if(i>start&&nums[i] == nums[i-1]) continue;
        sol.push_back(nums[i]);
        kSum(nums, i+1, end, target-nums[i], k-1, sol, res);
        sol.pop_back();
    }
}

vector<vector<int> > fourSum(vector<int> &nums, int target)
{
    vector<vector<int> > res;
    vector<int> sol;
    sort(nums.begin(), nums.end());
    kSum(nums, 0, nums.size()-1, target, 4, sol, res);
    return res;
}

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int> > res;
    res = fourSum(nums, target);
    for(int i = 0; i<res.size(); i++){
        for(int j = 0; j<res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

