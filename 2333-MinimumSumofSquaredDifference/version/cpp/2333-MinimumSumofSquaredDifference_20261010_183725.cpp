// Last updated: 10/10/2026, 6:37:25 PM
1class Solution {
2public:
3    long long minSumSquareDiff(std::vector<int>& nums1, std::vector<int>& nums2, int k1, int k2) {
4        long long k = (long long)k1 + k2;
5        int n = nums1.size();
6        
7        int maxDiff = 0;
8        for (int i = 0; i < n; ++i) {
9            maxDiff = std::max(maxDiff, std::abs(nums1[i] - nums2[i]));
10        }
11        
12        if (maxDiff == 0) return 0;
13        
14        std::vector<int> count(maxDiff + 1, 0);
15        for (int i = 0; i < n; ++i) {
16            count[std::abs(nums1[i] - nums2[i])]++;
17        }
18        
19        for (int d = maxDiff; d > 0 && k > 0; --d) {
20            if (count[d] == 0) continue;
21            
22            long long cnt = count[d];
23            if (k >= cnt) {
24                k -= cnt;
25                count[d - 1] += cnt;
26                count[d] = 0;
27            } else {
28                count[d] -= k;
29                count[d - 1] += k;
30                k = 0;
31            }
32        }
33        
34        long long result = 0;
35        for (long long d = 1; d <= maxDiff; ++d) {
36            if (count[d] > 0) {
37                result += count[d] * d * d;
38            }
39        }
40        
41        return result;
42    }
43};