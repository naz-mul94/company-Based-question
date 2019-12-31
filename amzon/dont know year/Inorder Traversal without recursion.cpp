/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) 
{
    vector<int> ans;
    if(!A)return ans;
    stack<TreeNode*> s;
    TreeNode* node=A;
    while(!s.empty()||node)
    {
        if(node)
        {
            s.push(node);
            node=node->left;
        }
        else
        {
            TreeNode* temp=s.top();
            s.pop();
            ans.push_back(temp->val);
            node=temp->right;
        }
    }
    return ans;
}
