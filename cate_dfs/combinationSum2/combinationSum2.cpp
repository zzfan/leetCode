/*************************************************************************
	> File Name: combinationSum2.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Thu 14 Jul 2016 10:19:16 PM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > result;
void dfs(vector<int> &candidates, int start, int target, vector<int> &sol)
{
    if(target == 0) result.push_back(sol);
    if(target < 0) return;
    if(target > 0){
        for(int i = start; i<candidates.size(); i++){
            //每次只读一个相同的数字
            if(i>start && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] <= target){
                sol.push_back(candidates[i]);
                dfs(candidates, i+1, target-candidates[i], sol);
                sol.pop_back();
            }
        }
    }
}

vector<vector<int> > combinationSum2(vector<int>& candidates, int target)
{
    result.clear();
    sort(candidates.begin(), candidates.end());
    vector<int> sol;
    dfs(candidates, 0, target, sol);
    return result;
}

int main()
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
//    vector<int> candidates = {1};
    int target = 8;
    vector<vector<int> > res;
    res = combinationSum2(candidates, target);
    for(int i = 0; i<res.size(); i++){
        for(int j = 0; j<res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}


