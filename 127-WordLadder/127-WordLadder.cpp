// Last updated: 7/25/2026, 11:01:38 PM
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set<string> s(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        s.erase(beginWord);
        if(s.find(endWord)==s.end()) return 0; 
        while(!q.empty()){
            string word=q.front().first;
            int step=q.front().second;
            q.pop();
            for(int i=0;i<word.size();i++){
                string newWord=word;
                for(int j='a';j<='z';j++){
                    newWord[i]=j;
                    if(newWord==endWord) return step+1;
                    if(s.find(newWord)!=s.end()){
                        q.push({newWord,step+1});
                        s.erase(newWord);
                    }
                }
            }
        }
        return 0;
    }
};