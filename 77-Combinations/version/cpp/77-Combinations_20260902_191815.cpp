// Last updated: 9/2/2026, 7:18:15 PM
1class Solution {
2public:
3    void count(int start, int n, int k,
4               vector<int>& temp,
5               vector<vector<int>>& all) {
6
7        if (k == 0) {
8            all.push_back(temp);
9            return;
10        }
11
12        for (int i = start; i <= n - k + 1; i++) {
13            temp.push_back(i);
14
15            count(i + 1, n, k - 1, temp, all);
16
17            temp.pop_back();
18        }
19    }
20
21    vector<vector<int>> combine(int n, int k) {
22        vector<int> temp;
23        vector<vector<int>> all;
24
25        count(1, n, k, temp, all);
26
27        return all;
28    }
29};
30
31
32    class Solution1 {
33    public:
34        void count(int n, int k, vector<int> & temp, vector<vector<int>> & all){
35            if(k==0){
36                all.push_back(temp);
37                return;
38            }
39            if(n==0){
40                return;
41            }
42            temp.push_back(n);
43            count(n-1,k-1,temp,all);
44            temp.pop_back();
45            count(n-1,k,temp,all);
46    }
47        vector<vector<int>> combine(int n, int k) {
48            vector<int> temp;
49            vector<vector<int>> all;
50            count(n,k,temp,all);
51            return all;
52        }
53    };