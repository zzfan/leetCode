/*************************************************************************
	> File Name: rotate.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Sat 30 Apr 2016 09:38:06 AM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

void myswap(vector<int>& nums, int start, int end)
{
    int temp;
    for(int i = 0; i<(end-start+1)/2; i++){
        temp = nums[start+i];
        nums[start+i] = nums[end-i];
        nums[end-i] = temp;
    }
}

void rotate(vector<int>& nums, int k)
{
    int len = nums.size();
    k %= len;
    myswap(nums, 0, len-1);
    myswap(nums, 0, k-1);
    myswap(nums, k, len-1);
}

void rotate1(vector<int>& nums, int k)
{
    int temp;
    int n = nums.size();
    for(int step = 0; step < k; step++){
        temp = nums[n-1];
        for(int i = n-1; i>0; i--){
            nums[i] = nums[i-1];
        }
        nums[0] = temp;
    }
}

void rotate2(int nums[], int n, int k)
{
    k = k%n;
    if(k==0) return;
    int *temp = new int[n];
    memcpy(temp, nums+(n-k), sizeof(int)*k);
    memcpy(temp+k, nums, sizeof(int)*(n-k));
    memcpy(nums, temp, sizeof(int)*n);
    delete [] temp;
}

int main()
{
    vector<int> nums;
    int n,temp,k;
    while(cin >> n >> k){
        for(int i = 0; i<n; i++){
            cin >> temp;
            nums.push_back(temp);
        }
        rotate(nums, k);
        for(int i = 0; i<n; i++){
            cout << nums[i];
        }
        cout << endl;
    }
}

