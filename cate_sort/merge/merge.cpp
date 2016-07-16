/*************************************************************************
	> File Name: merge.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Fri 15 Jul 2016 04:36:55 PM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int i,j;
    for(i = m-1, j = n-1; i>=0&&j>=0; ){
        if(nums1[i] > nums2[j]){
            nums1[i+j+1] = nums1[i];
            i--;
        }
        else{
            nums1[i+j+1] = nums2[j];
            j--;
        }
    }
    if(j>=0){
        for(int k = 0; k<=j; k++)
            nums1[k] = nums2[k];
    }
}


