// Last updated: 7/25/2026, 10:56:06 PM
class Solution {
public:
    static const int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        vector<int> pos, digit;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int k = digit.size();

        vector<long long> prefSum(k + 1, 0);
        vector<long long> prefNum(k + 1, 0);
        vector<long long> power10(k + 1, 1);

        for (int i = 1; i <= k; i++)
            power10[i] = (power10[i - 1] * 10) % MOD;

        for (int i = 0; i < k; i++) {
            prefSum[i + 1] = prefSum[i] + digit[i];
            prefNum[i + 1] = (prefNum[i] * 10 + digit[i]) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            long long sum = prefSum[R + 1] - prefSum[L];

            int len = R - L + 1;

            long long num = (prefNum[R + 1] -
                            (prefNum[L] * power10[len]) % MOD +
                            MOD) % MOD;

            ans.push_back((num * sum) % MOD);
        }

        return ans;
    }
};