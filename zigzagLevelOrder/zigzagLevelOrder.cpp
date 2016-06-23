/*************************************************************************
	> File Name: zigzagLevelOrder.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Thu 23 Jun 2016 01:18:23 PM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > zigzagLevelOrder(TreeNode* root)
{
    vector<vector<int> > result;
    queue<TreeNode*> que;
    vector<int> temp;
    int level = 0;
    if(root == NULL) return result;
    que.push(root);

    while(!(que.empty())){
        vector<int> temp;
        int len = que.size();
        level++;

        for(int i = 0; i<len; i++){
            TreeNode* a = que.front();
            que.pop();
            temp.push_back(a->val);
            if(a->left) que.push(a->left);
            if(a->right) que.push(a->right);
        }
        if(!(level%2)) reverse(temp.begin(), temp.end());
        result.push_back(temp);
    }
    return result;
}

