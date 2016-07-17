/*************************************************************************
	> File Name: firstMissingPositive.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Sat 07 May 2016 09:26:42 AM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

//要求的是常数空间
//扫描数组中每个数：
//1. 如果A[i]<1或者A[i]>n。说明A[i]一定不是first missing positive。跳过
//2. 如果A[i] = i+1，说明A[i]已经在正确的位置，跳过
//3. 如果A[i]!=i+1，且0<A[i]<=n，应当将A[i]放到A[A[i]-1]的位置，所以可以交换两数。
int firstMissingPositive(vector<int>& nums)
{
    int n = nums.size();
    int i = 0;
    while(i < n){
        //这里注意，当A[i] = A[A[i]-1]时会陷入死循环。这种情况下直接跳过。
        //千万要注意
        if(nums[i] != i+1 && nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i]-1]){
            int temp = nums[i];
            nums[i] = nums[temp-1];
            nums[temp-1] = temp;
        }
        else i++;
    }
    for(i = 0; i<n; i++){
        if(nums[i] != i+1) return i+1;
    }
    return n+1;
}

int firstMissingPositive1(vector<int>& nums)
{
    set<int> temp;
    int n = nums.size();
    for(int i = 0; i<n; i++){
        if(nums[i] > 0)
        temp.insert(nums[i]);
    }
    for(int m=1; ;m++){
        if(!temp.count(m))
        return m;
    }
}

int main()
{
    vector<int> nums = {-1, 2, 1, 3, 5};
    cout << firstMissingPositive(nums) << endl;
    cout << firstMissingPositive1(nums) << endl;
    return 0;
}

