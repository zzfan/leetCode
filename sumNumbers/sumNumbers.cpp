/*************************************************************************
	> File Name: sumNumbers.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Fri 10 Jun 2016 08:59:59 AM HKT
 ************************************************************************/

#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sum;

void dfs(TreeNode* root, int num)
{
    num = num*10 + root->val;
    if(root->left == NULL && root->right == NULL) sum += num;
    if(root->left) dfs(root->left, num);
    if(root->right) dfs(root->right, num);
}

int sumNumbers(TreeNode* root)
{
    sum = 0;
    int num = 0;
    if(root == NULL) return 0;
    dfs(root, num);
    return sum;
}
