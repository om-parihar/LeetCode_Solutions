// Last updated: 7/25/2026, 11:00:29 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void preorder(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &mp){
        if(root==NULL){
            return;
        }
        if(root->left){
            mp[root->left]=root;
            preorder(root->left,mp);
        }
        if(root->right){
            mp[root->right]=root;
            preorder(root->right,mp);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->left==q || p->right==q) return p;
        if(q->left==p || q->right==p) return q;
        unordered_map<TreeNode*,TreeNode*> mp;
        mp[root]=nullptr;
        preorder(root,mp);
        unordered_set<TreeNode*> s;
        while(p){
            s.insert(p);
            p=mp[p];
        }
        while(!s.count(q)){
            q=mp[q];
        }
        return q;
    }
};