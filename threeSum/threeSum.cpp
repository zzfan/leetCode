/*************************************************************************
	> File Name: threeSum.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Wed 30 Mar 2016 03:59:03 PM HKT
 ************************************************************************/

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > threeSum(vector<int>& nums)
{
    vector<vector<int> > result;
    vector<int> res = nums;
    vector<int> temp;
    sort(res.begin(), res.end());

    for(int i = 0; i<res.size(); i++){
        if(i>0 && res[i] == res[i-1]){
            continue;
        }

        int begin = i+1, end = res.size()-1;
        int target = -res[i];
        while(begin < end){
            if(begin > i+1 && res[begin] == res[begin-1]){
                begin++;
                continue;
            }
            if(res[begin] + res[end] < target){
                begin++;
                continue;
            }
            else if(res[begin] + res[end] > target){
                end--;
            }
            else{
                vector<int> temp;
                temp.push_back(res[i]);
                temp.push_back(res[begin]);
                temp.push_back(res[end]);
                result.push_back(temp);
                begin++;
            }
        }
    }
    return result;
}

int main()
{
    int count, temp;
    vector<int> nums;
    vector<vector<int> > solution;
    while(cin >> count){
        for(int i = 0; i<count; i++){
            cin >> temp;
            nums.push_back(temp);
        }
        solution = threeSum(nums);
        for(int i = 0; i<solution.size(); i++){
            for(int j = 0; j<solution[i].size(); j++){
                cout << (solution[i])[j] << " "; 
            }
            cout << endl;
        }
    }
}
