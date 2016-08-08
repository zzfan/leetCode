#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int len = nums.size(); 
    if(len < 2) return len;
    int end = 0;
    for(int i = 1; i<len; i++){
        if(nums[i] != nums[end]){
            end++;
            if(i!=end) nums[end] = nums[i];
        }
    }
    return end+1;
}
