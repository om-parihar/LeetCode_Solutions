// Last updated: 8/31/2026, 4:26:14 PM
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int N = n / 2;

        vector<vector<int>> left(N + 1);
        vector<vector<int>> right(N + 1);

        for (int mask = 0; mask < (1 << N); mask++) {
            int cnt = 0, sum = 0;

            for (int i = 0; i < N; i++) {
                if (mask & (1 << i)) {
                    cnt++;
                    sum += nums[i];
                }
            }

            left[cnt].push_back(sum);
        }

        for (int mask = 0; mask < (1 << N); mask++) {
            int cnt = 0, sum = 0;

            for (int i = 0; i < N; i++) {
                if (mask & (1 << i)) {
                    cnt++;
                    sum += nums[N + i];
                }
            }

            right[cnt].push_back(sum);
        }

        for (int i = 0; i <= N; i++) {
            sort(right[i].begin(), right[i].end());
        }

        int total = accumulate(nums.begin(), nums.end(), 0);
        int ans = INT_MAX;

        for (int cnt = 0; cnt <= N; cnt++) {
            int need = N - cnt;

            for (int sum1 : left[cnt]) {

                int target = total / 2 - sum1;

                auto it = lower_bound(
                    right[need].begin(),
                    right[need].end(),
                    target
                );

                if (it != right[need].end()) {
                    int sum2 = *it;
                    ans = min(ans, abs(total - 2 * (sum1 + sum2)));
                }

                if (it != right[need].begin()) {
                    --it;
                    int sum2 = *it;
                    ans = min(ans, abs(total - 2 * (sum1 + sum2)));
                }
            }
        }

        return ans;
    }
};