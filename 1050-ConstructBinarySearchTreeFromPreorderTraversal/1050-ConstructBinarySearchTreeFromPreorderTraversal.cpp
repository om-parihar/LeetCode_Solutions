// Last updated: 7/25/2026, 10:57:55 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* BST(vector<int> preorder,int &idx, int lb, int up){
        if(idx==preorder.size() || preorder[idx]<lb || preorder[idx]>up){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[idx++]);
        root->left=BST(preorder,idx,lb,root->val);
        root->right=BST(preorder,idx,root->val,up);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx=0;
        return BST(preorder,idx,INT_MIN,INT_MAX);
    }
};