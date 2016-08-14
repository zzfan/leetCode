/*************************************************************************
	> File Name: removeElement.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Mon 20 Jun 2016 10:36:33 AM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

//尽量自己动手
int removeElement(vector<int>& nums, int val)
{
    int newIndex = 0; 
    for(int oldIndex = 0; oldIndex < nums.size(); oldIndex++){
        if(nums[oldIndex] != val){
            nums[newIndex++] = nums[oldIndex];
        }
    }
    return newIndex;
}

int main()
{
    vector<int> nums = {1, 1, 2, 2, 3, 4};
    int val = 1;
    int len = removeElement(nums, val);
    for(int i = 0; i<len; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

