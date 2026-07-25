// Last updated: 7/25/2026, 10:57:57 PM
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> common_freq(26,INT_MAX);

    for (const string& word : words) {
        vector<int> word_freq(26, 0);
        for (char c : word) {
            word_freq[c - 'a']++;
        }
        for (int i = 0; i < 26; ++i) {
            common_freq[i] = min(common_freq[i], word_freq[i]);
        }
    }
    vector<string> result;
    for (int i = 0; i < 26; ++i) {
        while (common_freq[i] > 0) {
            result.push_back(string(1, i + 'a'));
            common_freq[i]--;
        }
    }
    
    return result;
    }
};