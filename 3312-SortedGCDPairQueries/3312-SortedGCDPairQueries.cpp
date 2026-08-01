// Last updated: 8/1/2026, 4:54:02 PM
1// public:   SOLUTION 1
2//     int gcd(int a, int b){
3//         while(b){
4//             int temp=a%b;
5//             a=b;
6//             b=temp;
7//         }
8//         return a;
9//     }
10//     vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
11//         int n=nums.size();
12//         int m=queries.size();
13//         map<pair<int,int>, int> gcdPairs;
14//         vector<int> temp;
15//         for(int i=0;i<n-1;i++){
16//             for(int j=i+1;j<n;j++){
17//                 pair<int,int> p={nums[i],nums[j]};
18//                 if(gcdPairs.find(p)==gcdPairs.end()){
19//                     gcdPairs[p]=gcd(nums[i],nums[j]);
20//                 }
21//                 temp.push_back(gcdPairs[p]);
22//             }
23//         }
24//         sort(temp.begin(),temp.end());
25//         vector<int> answer(m,0);
26//         for(int i=0;i<m;i++){
27//             answer[i]=temp[queries[i]];
28//         }
29//         return answer;
30//     }
31// };
32
33
34
35// Solution 2
36
37class Solution {
38public:
39    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
40
41        int mx = *max_element(nums.begin(), nums.end());
42
43        vector<long long> freq(mx + 1);
44
45        for (int x : nums)
46            freq[x]++;
47
48        vector<long long> cnt(mx + 1);
49
50        for (int d = 1; d <= mx; d++) {
51            for (int multiple = d; multiple <= mx; multiple += d)
52                cnt[d] += freq[multiple];
53        }
54
55        vector<long long> exact(mx + 1);
56
57        for (int d = mx; d >= 1; d--) {
58            exact[d] = cnt[d] * (cnt[d] - 1) / 2;
59            for (int multiple = 2 * d; multiple <= mx; multiple += d)
60                exact[d] -= exact[multiple];
61        }
62
63        vector<long long> prefix(mx + 1);
64
65        for (int i = 1; i <= mx; i++)
66            prefix[i] = prefix[i - 1] + exact[i];
67
68        vector<int> ans;
69
70        for (long long q : queries) {
71            int g = lower_bound(prefix.begin(), prefix.end(), q + 1) - prefix.begin();
72            ans.push_back(g);
73        }
74
75        return ans;
76    }
77};