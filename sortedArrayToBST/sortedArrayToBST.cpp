/*************************************************************************
	> File Name: sortedArrayToBST.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Sun 24 Apr 2016 10:24:50 AM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

TreeNode* buildTree(vector<int>& nums, int start, int end)
{
    if(start > end) return NULL;
    if(start == end) return new TreeNode(nums[start]);
    int middle = (start + end)/2;
    TreeNode *node = new TreeNode(nums[middle]);
    node->left = buildTree(nums, start, middle-1);
    node->right = buildTree(nums, middle+1, end);
    return node;
}

TreeNode* sortedArrayToBST(vector<int>& nums)
{
    return BuildTree(nums, 0, nums.size()-1);
}

