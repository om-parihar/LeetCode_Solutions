// Last updated: 7/25/2026, 10:58:56 PM
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
    int widthOfBinaryTree(TreeNode* root) {
        long long ans=INT_MIN;
        if(!root){
            return 0;
        }
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            long long first=q.front().second;
            long long last=first;
            for(int i=0;i<size;i++){
                auto node=q.front();
                q.pop();
                TreeNode* curr=node.first;
                long long idx=node.second-first;
                last=idx; 
                if(curr->left){
                    q.push({curr->left,2*idx+1});
                }
                if(curr->right){
                    q.push({curr->right,2*idx+2});
                }
            }
            ans=max(ans,last+1);
        }
        return ans;
    }
};