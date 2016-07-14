/*************************************************************************
	> File Name: combinationSum.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Thu 14 Jul 2016 08:25:58 PM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

//哈哈，现在感觉做这种题很简单
set<vector<int> > result;
void dfs(vector<int>& candidates, int target, vector<int> combi)
{
    if(target == 0){
        sort(combi.begin(), combi.end());
        result.insert(combi);
    }
    if(target < 0) return;
    if(target > 0){
        for(int i = 0; i<candidates.size(); i++){
            combi.push_back(candidates[i]);
            dfs(candidates, target-candidates[i], combi);
            combi.pop_back();
        }
    }
}

vector<vector<int> > combinationSum(vector<int>& candidates, int target)
{
    result.clear();
    vector<vector<int> > combires;
    vector<int> combi;
    dfs(candidates, target, combi);
    combires.assign(result.begin(), result.end());
    return combires;
}

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 14;
    vector<vector<int> > com = combinationSum(candidates, target);
    for(int i = 0; i<com.size(); i++){
        for(int j = 0; j<com[i].size(); j++)
            cout << com[i][j] << " ";
        cout << endl;
    }
}

