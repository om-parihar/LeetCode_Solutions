// Last updated: 8/31/2026, 4:24:51 PM
class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26);

        for (char c : s)
            cnt[c - 'a']++;

        vector<int> temp = cnt;
        int pos = -1;

        for (int i = 0; i < n; i++) {
            int x = target[i] - 'a';

            for (int j = x + 1; j < 26; j++) {
                if (temp[j] > 0) {
                    pos = i;
                    break;
                }
            }

            if (temp[x] == 0)
                break;

            temp[x]--;
        }

        if (pos == -1)
            return "";

        string ans;

        for (int i = 0; i < pos; i++) {
            ans += target[i];
            cnt[target[i] - 'a']--;
        }

        int x = target[pos] - 'a';

        for (int j = x + 1; j < 26; j++) {
            if (cnt[j] > 0) {
                ans += char('a' + j);
                cnt[j]--;
                break;
            }
        }

        for (int i = 0; i < 26; i++) {
            while (cnt[i] > 0) {
                ans += char('a' + i);
                cnt[i]--;
            }
        }

        return ans;
    }
};