// Last updated: 11/25/2026, 4:13:50 PM
1class Trie {
2public:
3    unordered_map<string,int> mp;
4    Trie() {
5        mp.clear();
6    }
7    
8    void insert(string word) {
9        mp[word]++;
10    }
11    
12    bool search(string word) {
13        if(mp.find(word)!=mp.end()){
14            return true;
15        }
16        return false;
17    }
18    
19    bool startsWith(string prefix) {
20        for(auto it: mp){
21            string x=it.first;
22            if(x[0]==prefix[0]){
23                int cnt=0;
24                for(int i=0;i<min(x.size(),prefix.size());i++){
25                    if(x[i]==prefix[i]){
26                        cnt++;
27                    }
28                }
29                if(cnt==prefix.size()){
30                    return true;
31                }
32            }
33        }
34        return false;
35    }
36};
37
38/**
39 * Your Trie object will be instantiated and called as such:
40 * Trie* obj = new Trie();
41 * obj->insert(word);
42 * bool param_2 = obj->search(word);
43 * bool param_3 = obj->startsWith(prefix);
44 */