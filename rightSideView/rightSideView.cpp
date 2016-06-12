#include <iostream>
#include <vector>

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> rightSideView(TreeNode* root)
{
    vector<int> result;
    if(root == NULL) return result;
    queue<TreeNode*> q;

    q.push(root);
    while(!q.empty()){
        result.push_back(q.back()->val);
        int size = q.size();
        for(int i = 0; i<size; ++i){
            TreeNode *node = q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    return result;
}
