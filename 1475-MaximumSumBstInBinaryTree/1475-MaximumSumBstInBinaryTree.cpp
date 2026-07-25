// Last updated: 7/25/2026, 10:57:22 PM
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
    struct NodeInfo {
        bool isBST;
        int mini;
        int maxi;
        int sum;
    };

    int ans = 0;

    NodeInfo check(TreeNode* root) {

        if (root == NULL) {
            return {true, INT_MAX, INT_MIN, 0};
        }

        NodeInfo left = check(root->left);
        NodeInfo right = check(root->right);

        NodeInfo curr;

        if (left.isBST &&
            right.isBST &&
            root->val > left.maxi &&
            root->val < right.mini) {

            curr.isBST = true;

            curr.sum = left.sum + right.sum + root->val;

            curr.mini = min(root->val, left.mini);

            curr.maxi = max(root->val, right.maxi);

            ans = max(ans, curr.sum);

            return curr;
        }

        curr.isBST = false;
        curr.sum = 0;
        curr.mini = INT_MIN;
        curr.maxi = INT_MAX;

        return curr;
    }

    int maxSumBST(TreeNode* root) {
        check(root);
        return ans;
    }
};