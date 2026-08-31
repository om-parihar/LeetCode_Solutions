// Last updated: 8/31/2026, 4:25:40 PM
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int i = 0;
        int cnt = 0;

        string ans = "";

        for (int j = 0; j < n; j++) {

            if (s[j] == '1')
                cnt++;

            while (cnt == k) {

                string curr = s.substr(i, j - i + 1);

                if (ans.empty() ||
                    curr.size() < ans.size() ||
                    (curr.size() == ans.size() && curr < ans)) {
                    ans = curr;
                }

                if (s[i] == '1')
                    cnt--;

                i++;
            }
        }

        return ans;
    }
};