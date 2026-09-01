// Last updated: 9/1/2026, 2:26:35 PM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    pair<int,int> solve(TreeNode* root, priority_queue<int>& pq, bool& perfect) {
15    if (root == NULL) {
16        perfect = true;
17        return {0, 0};
18    }
19
20    bool leftPerfect, rightPerfect;
21
22    auto left = solve(root->left, pq, leftPerfect);
23    auto right = solve(root->right, pq, rightPerfect);
24
25    int size = 1 + left.first + right.first;
26    int height = 1 + max(left.second, right.second);
27
28    perfect = leftPerfect &&
29              rightPerfect &&
30              left.second == right.second;
31
32    if (perfect) {
33        pq.push(size);
34    }
35
36    return {size, height};
37}
38    int kthLargestPerfectSubtree(TreeNode* root, int k) {
39        if(root==NULL) return 0;
40        priority_queue<int> pq;
41        bool perfect;
42        solve(root,pq,perfect);
43        int ans=-1;
44        if(k>pq.size()) return ans;
45        while(k){
46            ans=pq.top();
47            pq.pop();
48            k--;
49        }
50        return ans;
51    }
52};