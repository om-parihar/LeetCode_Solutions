// Last updated: 9/17/2026, 10:17:55 AM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10class Codec {
11public:
12    void dfs(TreeNode* root,string& a){
13        if(root==NULL){
14            a+="#,";
15            return;
16        }
17        a+=to_string(root->val);
18        a+=',';
19        dfs(root->left,a);
20        dfs(root->right,a);
21    }
22
23    // Encodes a tree to a single string.
24    string serialize(TreeNode* root) {
25        string a;
26        dfs(root,a);
27        return a;
28    }
29
30    TreeNode* build(string& data,int& i){
31        if(data[i]=='#'){
32            i+=2;
33            return NULL;
34        }
35        int num=0;
36        while(data[i]!=','){
37            num=num*10+(data[i]-'0');
38            i++;
39        }
40        i++;
41        TreeNode* root=new TreeNode(num);
42        root->left=build(data,i);
43        root->right=build(data,i);
44        return root;
45    }
46
47    // Decodes your encoded data to tree.
48    TreeNode* deserialize(string data) {
49        int i=0;
50        return build(data,i);
51    }
52};
53
54// Your Codec object will be instantiated and called as such:
55// Codec* ser = new Codec();
56// Codec* deser = new Codec();
57// string tree = ser->serialize(root);
58// TreeNode* ans = deser->deserialize(tree);
59// return ans;