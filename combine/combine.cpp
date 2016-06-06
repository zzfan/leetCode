/*************************************************************************
	> File Name: combine.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Tue 26 Apr 2016 07:22:00 PM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

void findcomb(int n, int start, int k, vector<int>& temp, vector<vector<int> >& result)
{
    if(k == 0){
        result.push_back(temp);
        return;
    }

    for(int i = start; i <= n-k+1; i++){
        temp.push_back(i);
        findcomb(n, i+1, k-1, temp, result);
        temp.pop_back();
    }
}

vector<vector<int> > combine(int n, int k)
{
    vector<int> temp;
    vector<vector<int> > result;
    findcomb(n, 1, k, temp, result);
    return result;
}

int main()
{
    int n, k;
    vector<vector<int> > result;
    while(cin >> n >> k){
        result = combine(n, k);
        int size = result.size();
        for(int i = 0; i<size; i++){
            for(int j = 0; j<result[i].size(); j++){
                cout << result[i][j] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}

