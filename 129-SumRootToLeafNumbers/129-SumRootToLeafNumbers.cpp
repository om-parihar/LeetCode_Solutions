// Last updated: 8/31/2026, 4:33:48 PM
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

// Morris Traversal
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum=0;
        int currsum=0;
        while(root!=NULL){
            if(root->left!=NULL){
                TreeNode* node=root->left;
                int steps=1;
                while(node->right && node->right!=root){
                    node=node->right;
                    steps++;
                }
                if(node->right==NULL){
                    node->right=root;
                    currsum=currsum*10+root->val;
                    root=root->left;
                }
                else{
                    node->right=NULL;
                    if(node->left==NULL){
                        sum+=currsum;
                    }
                    while(steps){
                        currsum=currsum/10;
                        steps--;
                    }
                    root=root->right;
                }
            }
            else{
                currsum=currsum*10+root->val;
                if(root->right==NULL){
                    sum+=currsum;
                }
                root=root->right;
            }
        }
        return sum;
    }
};

class Solution2 {
public:
    int sumNumbers(TreeNode* root) {
        stack<pair<TreeNode*,int>> st;
        st.push({root,0});
        int sum=0;
        while(!st.empty()){
            auto node=st.top().first;
            int curr=st.top().second;
            st.pop();
            curr=curr*10+node->val;
            if(!node->left && !node->right){
                sum+=curr;
            }
            if(node->left){
                st.push({node->left,curr});
            }
            if(node->right){
                st.push({node->right,curr});
            }
        }
        return sum;
    }
};

class Solution1 {
public:
    void trav(TreeNode* root, int &ans, int sum){
        if(root==NULL){
            return;
        }
        sum=sum*10+root->val;
        if(!root->left && !root->right){
            ans+=sum;
            return;
        }
        trav(root->left,ans,sum);
        trav(root->right,ans,sum);
    }
    int sumNumbers(TreeNode* root) {
        int ans=0;
        int sum=0;
        trav(root,ans,sum);
        return ans;
    }
};