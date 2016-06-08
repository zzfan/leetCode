/*************************************************************************
	> File Name: preorderTraversal.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Wed 08 Jun 2016 06:00:58 PM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

//递归算法
vector<int> preorder(TreeNode* root, vector<int> path)
{
    if(root != NULL){
        path.push_back(root->val);
        preorder(root->left, path);
        preorder(root->right, path);
    }
}

vector<int> preorderTraversal1(TreeNode* root)
{
    vector<int> path;
    preorder(root, path);
    return path;
}

//非递归算法,迭代
vector<int> preorderTraversal(TreeNode* root)
{
    vector<int> path;
    stack<TreeNode*> stk;
    while(root != NULL || !stk.empty()){
        if(root != NULL){
            while(root){
                path.push_back(root->val);
                stk.push(root);
                root = root->left;
            }
        }
        else{
            root = stk.top()->right;
            stk.pop();
        }
    }
    return path;
}


