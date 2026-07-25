// Last updated: 7/25/2026, 11:01:39 PM
class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parent;
    unordered_map<string, int> level;

    void dfs(string word, string beginWord, vector<string> &path) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for (auto &p : parent[word]) {
            path.push_back(p);
            dfs(p, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        if (st.find(endWord) == st.end())
            return {};

        queue<string> q;
        q.push(beginWord);
        level[beginWord] = 0;

        while (!q.empty()) {
            string word = q.front();
            q.pop();

            string original = word;

            for (int i = 0; i < word.size(); i++) {
                char old = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;

                    if (st.find(word) == st.end())
                        continue;

                    if (!level.count(word)) {
                        level[word] = level[original] + 1;
                        q.push(word);
                        parent[word].push_back(original);
                    }
                    else if (level[word] == level[original] + 1) {
                        parent[word].push_back(original);
                    }
                }

                word[i] = old;
            }
        }

        if (!level.count(endWord))
            return {};

        vector<string> path;
        path.push_back(endWord);

        dfs(endWord, beginWord, path);

        return ans;
    }
};