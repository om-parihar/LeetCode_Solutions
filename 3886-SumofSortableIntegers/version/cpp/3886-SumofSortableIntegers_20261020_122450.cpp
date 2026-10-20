// Last updated: 10/20/2026, 12:24:50 PM
1class Solution {
2public:
3    int sortableIntegers(std::vector<int>& nums) {
4        int n = nums.size();
5        
6        auto isSortable = [&](int k) -> bool {
7            int num_blocks = n / k;
8            int prev_max = -1;
9            
10            for (int b = 0; b < num_blocks; ++b) {
11                int start = b * k;
12                int end = start + k;
13                
14                int curr_min = nums[start];
15                int curr_max = nums[start];
16                int drops = 0;
17                
18                for (int i = start; i < end; ++i) {
19                    curr_min = std::min(curr_min, nums[i]);
20                    curr_max = std::max(curr_max, nums[i]);
21                    
22                    int next_val = (i + 1 == end) ? nums[start] : nums[i + 1];
23                    if (nums[i] > next_val) {
24                        drops++;
25                    }
26                }
27                
28                if (drops > 1) return false;
29                
30                if (prev_max > curr_min) return false;
31                
32                prev_max = curr_max;
33            }
34            return true;
35        };
36
37        int ans = 0;
38        for (int k = 1; k <= n; ++k) {
39            if (n % k == 0) {
40                if (isSortable(k)) {
41                    ans += k;
42                }
43            }
44        }
45        
46        return ans;
47    }
48};