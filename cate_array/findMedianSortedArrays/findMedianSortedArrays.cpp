/*************************************************************************
	> File Name: findMedianSortedArrays.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Fri 05 Aug 2016 08:38:31 PM CST
 ************************************************************************/

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findKthNum(vector<int> &nums1, vector<int> &nums2, int k)
{
    int m = nums1.size(), n = nums2.size();
    if(m == 0) return nums2[k-1];
    if(n == 0) return nums1[k-1];
    int i = m/2, j = n/2;
    if(nums1[i] <= nums2[j]){
        if(k>i+j+1){
            vector<int> temp(nums1.begin()+i+1, nums1.end());
            return findKthNum(temp, nums2, k-i-1);
        }
        else{
            vector<int> temp(nums2.begin(), nums2.begin()+j);
            return findKthNum(nums1, temp, k);
        }
    }
    else{
        if(k>i+j+1){
            vector<int> temp(nums2.begin()+j+1, nums2.end());
            return findKthNum(nums1, temp, k-j-1);
        }
        else{
            vector<int> temp(nums1.begin(), nums1.begin()+i);
            return findKthNum(temp, nums2, k);
        }
    }
}

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int m = nums1.size(), n = nums2.size();
    int mid = (m+n)/2;
    if((m+n)%2)
        return (double)findKthNum(nums1, nums2, mid+1);
    else{
        int mid1 = findKthNum(nums1, nums2, mid);
        int mid2 = findKthNum(nums1, nums2, mid+1);
        return 0.5*(mid1+mid2);
    }
}
