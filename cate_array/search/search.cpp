#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int search(vector<int>& nums, int target)
{
    int len = nums.size();
    int start = 0, end = len-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(nums[mid] == target) return mid;
        if(nums[mid] < nums[end]){
            //有半部分是排好序的
            if(target > nums[mid] && target <= nums[end])
                start = mid+1;
            else
                end = mid-1;
        }
        else{
            //左半部分时有序的
            if(target < nums[mid] && target >= nums[start]) 
                end = mid-1;
            else
                start = mid+1;
        }
    }
    return -1;
}
