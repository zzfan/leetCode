/*************************************************************************
	> File Name: countRangeSum.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Wed 04 May 2016 06:32:50 PM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

//这道题目看了我半天才看懂，我也是醉了，题目意思挺好理解的
int countRangeSum(vector<int>& nums, int lower, int upper)
{
    if(nums.size() == 0) return 0;
    vector<long> sum(nums.size()+1, 0);
    for(int i = 0; i<nums.size(); i++){
        sum[i+1] = sum[i] + nums[i];
    }

    int ans = 0;
    for(int i = 0; i<nums.size(); i++){
        for(int j = i+1; j <= nums.size(); j++){
            if(lower <= sum[j] - sum[i] && sum[j] - sum[i] <= upper)
            ans++;
        }
    }
    return ans;
}

//上面的方法是O(n*n)的，下面介绍一个简单的方法

int countAndMergeSort(vector<long> &sums, int start, int end, int lower, int upper)
{
    if(end -start <= 1) return 0;
    int mid = start + (end - start)/2;
    int cnt = countAndMergeSort(sums, start, mid, lower, upper) + countAndMergeSort(sums, mid, end, lower, upper);
    int j = mid, k = mid, t = mid;
    vector<int> cache(end - start, 0);
    for(int i = start, r = 0; i<mid; ++i, ++r){
        while(k < end && sums[k] - sums[i] < lower) ++k;
        while(j < end && sums[j] - sums[i] <= upper) ++j;
        while(t < end && sums[t] < sums[i]) cache[r++] = sums[t++];
        cache[r] = sums[i];
        cnt += j-k;
    }
    copy(cache.begin(), cache.begin() + t - start, sums.begin() + start);
    return cnt;
}

int countRangeSum1(vector<int>& nums, int lower, int upper)
{
    vector<long> sums(nums.size()+1, 0);
    for(int i = 0; i<nums.size(); i++){
        sums[i+1] = sums[i] + nums[i];
    }

    return countAndMergeSort(sums, 0, sums.size(), lower, upper);
}


int main()
{
    vector<int> nums;
    int n, temp;
    while(cin >> n){
        for(int i = 0; i<n; i++){
            cin >> temp;
            nums.push_back(temp);
        }
        cout << countRangeSum1(nums, -2, 2) << endl;
    }
    return 0;
}
