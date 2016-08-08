#include <iostream>
#include <vector>
using namespace std;

bool search(vector<int> &nums, int target)
{
    int len = nums.size(); 
    int start = 0, end = len-1;
    while(start <= end){
        int mid = start + (end-start)/2;
        if(nums[mid] == target) return true;
        if(nums[mid]<nums[end]){
            if(target > nums[mid] && target <= nums[end])
                start = mid+1;
            else
                end = mid-1;
        }
        else if(nums[mid] > nums[end]){
            if(target >= nums[start] && target < nums[mid])
                end = mid -1;
            else
                start = mid+1;
        }
        else{
            end--;
        }
    }
    return false;
}
