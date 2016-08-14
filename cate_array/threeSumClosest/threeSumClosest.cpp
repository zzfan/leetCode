/*************************************************************************
	> File Name: threeSumClosest.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Mon 04 Apr 2016 12:48:11 PM HKT
 ************************************************************************/

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int threeSumCloest(vector<int>& nums, int target)
{
    int result = abs(nums[0]+nums[1]+nums[2]);
    vector<int> temp = nums;
    sort(temp.begin(), temp.end());

    for(int i = 0; i<temp.size(); i++){
        int start = i + 1, end = temp.size() - 1;
        while(start < end){
            if(abs(result - target) > abs(temp[i] + temp[start] + temp[end] - target)){
                result = temp[i] + temp[start] + temp[end];
            }
            if(temp[i] + temp[start] + temp[end] < target){
                start++;
            }
            else{
                end--;
            }
        }
    }
    return result;
}

int main()
{
    int target, size;
    int temp;
    vector<int> nums;
    while(cin >> size){
        for(int i = 0; i<size; i++){
            cin >> temp;
            nums.push_back(temp);
        }
        cin >> target;
        cout << threeSumCloest(nums, target) << endl;
    }
}
