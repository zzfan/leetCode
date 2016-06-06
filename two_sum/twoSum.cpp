/*************************************************************************
	> File Name: twoSum.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Wed 23 Mar 2016 07:00:01 PM PDT
 ************************************************************************/

#include<iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int> result;
    for(int i=0; i<nums.size(); i++)
    for(int j=i+1; j<nums.size(); j++){
        if(target == nums[i] + nums[j]){
            result.push_back(i);
            result.push_back(j);
            return result;
        }
    }
    return result;
}

int main()
{
    vector<int> nums;
    vector<int> result;
    int target,temp;
    for(int i = 0; i<5; i++){
        cin >> temp;
        nums.push_back(temp);
    }
    cin >> target;
    result = twoSum(nums, target);
    for(int i = 0; i<result.size(); i++){
        cout << result[i] << endl;
    }
}
