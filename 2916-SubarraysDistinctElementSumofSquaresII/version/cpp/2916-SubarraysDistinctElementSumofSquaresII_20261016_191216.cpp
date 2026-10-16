// Last updated: 10/16/2026, 7:12:16 PM
1
2class Solution {
3public:
4    static const int MOD = 1e9 + 7;
5
6    struct Node {
7        long long sum = 0;
8        long long sq = 0;
9        long long lazy = 0;
10    };
11
12    vector<Node> tree;
13    int n;
14
15    void apply(int node, int l, int r, long long val) {
16        long long len = r - l + 1;
17        tree[node].sq = (tree[node].sq
18            + 2 * val % MOD * tree[node].sum % MOD
19            + len * val % MOD * val % MOD) % MOD;
20
21        tree[node].sum = (tree[node].sum + len * val) % MOD;
22        tree[node].lazy = (tree[node].lazy + val) % MOD;
23    }
24
25    void push(int node, int l, int r) {
26        if (tree[node].lazy == 0 || l == r) return;
27
28        int mid = (l + r) / 2;
29        apply(node * 2, l, mid, tree[node].lazy);
30        apply(node * 2 + 1, mid + 1, r, tree[node].lazy);
31        tree[node].lazy = 0;
32    }
33
34    void update(int node, int l, int r, int ql, int qr, int val) {
35        if (ql > r || qr < l) return;
36
37        if (ql <= l && r <= qr) {
38            apply(node, l, r, val);
39            return;
40        }
41
42        push(node, l, r);
43        int mid = (l + r) / 2;
44
45        update(node * 2, l, mid, ql, qr, val);
46        update(node * 2 + 1, mid + 1, r, ql, qr, val);
47
48        tree[node].sum = (tree[node * 2].sum + tree[node * 2 + 1].sum) % MOD;
49        tree[node].sq = (tree[node * 2].sq + tree[node * 2 + 1].sq) % MOD;
50    }
51
52    int sumCounts(vector<int>& nums) {
53        n = nums.size();
54        tree.resize(4 * n);
55
56        unordered_map<int, int> last;
57        long long ans = 0;
58
59        for (int i = 0; i < n; i++) {
60            int prev = last.count(nums[i]) ? last[nums[i]] : -1;
61
62            update(1, 0, n - 1, prev + 1, i, 1);
63
64            ans = (ans + tree[1].sq) % MOD;
65            last[nums[i]] = i;
66        }
67
68        return ans;
69    }
70};
71