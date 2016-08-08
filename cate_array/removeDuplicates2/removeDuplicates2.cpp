#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int len = nums.size();
    if(len < 3) return len;
    int end = 1;
    for(int i = 2; i<len; i++){
        if(nums[i] != nums[end-1]){
            end++;
            if(i!=end) nums[end] = nums[i];
        }
    }
    return end+1;
}
