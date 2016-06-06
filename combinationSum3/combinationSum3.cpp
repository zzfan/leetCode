/*************************************************************************
	> File Name: combinationSum3.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Sat 16 Apr 2016 09:42:38 PM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

void dfs(int k, int n, int idx, int sum, int cnt, vector<int> &path, vector<vector<int> > &res)
{
    if (sum > n || cnt > k || idx > 10) return;
    if (sum == n && cnt == k){
        res.push_back(path);
        return;
    }

    dfs(k, n, idx+1, sum, cnt, path, res);
    path.push_back(idx);
    dfs(k, n, idx+1, sum+idx, cnt+1, path, res);
    path.pop_back();
}

vector<vector<int> > combinationSum3(int k, int n)
{
    vector<vector<int> > res;
    vector<int> path;
    dfs(k, n, 1, 0, 0, path, res);
    return res;
}

int main()
{
    vector<vector<int> > res;
    int k, n;
    while(cin >> k >> n){
        res.clear();
        res = combinationSum3(k, n);
        cout << "[";
        for(int i = 0; i<res.size(); i++){
            cout << "[";
            for(int j = 0; j<res[i].size(); j++){
                cout << res[i][j];
                if(j != res[i].size()-1)
                cout << ",";
            }
            cout << "]";
            if(i != res.size()-1)
            cout << ",";
        }
        cout << "]" << endl;
    }
    return 0;
    
}
