/*************************************************************************
	> File Name: combinationSum2.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Thu 14 Jul 2016 10:19:16 PM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

set<vector<int> > result;
map<int, int> flag;

void dfs(vector<int> candidates, int target, vector<int> nums)
{
    if(target < 0) return;
    if(target == 0){
        sort(nums.begin(), nums.end());
        result.insert(nums);
    }
    if(target > 0){
        for(int i = 0; i<candidates.size(); i++){
            if(flag[candidates[i]] > 0){
                nums.push_back(candidates[i]);
                flag[candidates[i]]--;
                dfs(candidates, target-candidates[i], nums);
                flag[candidates[i]]++;
                nums.pop_back();
            }
        }
    }
}

vector<vector<int> > combinationSum2(vector<int>& candidates, int target)
{
    result.clear();
    vector<vector<int> > res;
    vector<int> nums;
    for(int i = 0; i<candidates.size(); i++){
        if(flag.find(candidates[i]) == flag.end()){
            flag[candidates[i]] = 1;
        }
        else{
            flag[candidates[i]]++;
        }
    }
    dfs(candidates, target, nums);
    res.assign(result.begin(), result.end());
    return res;
}

int main()
{
//    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    vector<int> candidates = {1};
    int target = 2;
    vector<vector<int> > res;
    res = combinationSum2(candidates, target);
    for(int i = 0; i<res.size(); i++){
        for(int j = 0; j<res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}


