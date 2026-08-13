// Last updated: 8/13/2026, 2:26:50 PM
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
12
13// Morris Traversal
14class Solution {
15public:
16    int sumNumbers(TreeNode* root) {
17        int sum=0;
18        int currsum=0;
19        while(root!=NULL){
20            if(root->left!=NULL){
21                TreeNode* node=root->left;
22                int steps=1;
23                while(node->right && node->right!=root){
24                    node=node->right;
25                    steps++;
26                }
27                if(node->right==NULL){
28                    node->right=root;
29                    currsum=currsum*10+root->val;
30                    root=root->left;
31                }
32                else{
33                    node->right=NULL;
34                    if(node->left==NULL){
35                        sum+=currsum;
36                    }
37                    while(steps){
38                        currsum=currsum/10;
39                        steps--;
40                    }
41                    root=root->right;
42                }
43            }
44            else{
45                currsum=currsum*10+root->val;
46                if(root->right==NULL){
47                    sum+=currsum;
48                }
49                root=root->right;
50            }
51        }
52        return sum;
53    }
54};
55
56class Solution2 {
57public:
58    int sumNumbers(TreeNode* root) {
59        stack<pair<TreeNode*,int>> st;
60        st.push({root,0});
61        int sum=0;
62        while(!st.empty()){
63            auto node=st.top().first;
64            int curr=st.top().second;
65            st.pop();
66            curr=curr*10+node->val;
67            if(!node->left && !node->right){
68                sum+=curr;
69            }
70            if(node->left){
71                st.push({node->left,curr});
72            }
73            if(node->right){
74                st.push({node->right,curr});
75            }
76        }
77        return sum;
78    }
79};
80
81class Solution1 {
82public:
83    void trav(TreeNode* root, int &ans, int sum){
84        if(root==NULL){
85            return;
86        }
87        sum=sum*10+root->val;
88        if(!root->left && !root->right){
89            ans+=sum;
90            return;
91        }
92        trav(root->left,ans,sum);
93        trav(root->right,ans,sum);
94    }
95    int sumNumbers(TreeNode* root) {
96        int ans=0;
97        int sum=0;
98        trav(root,ans,sum);
99        return ans;
100    }
101};