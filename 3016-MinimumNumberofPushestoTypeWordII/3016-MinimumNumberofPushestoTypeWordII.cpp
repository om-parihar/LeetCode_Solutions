// Last updated: 7/31/2026, 12:01:27 PM
1class Solution {
2public:
3    int minimumPushes(string word) {
4        int n=word.size();
5        string words="";
6        unordered_map<char, int> freq;
7
8        for(char c : word)
9            freq[c]++;
10
11        vector<pair<char,int>> v(freq.begin(), freq.end());
12
13        sort(v.begin(), v.end(), [](auto &a, auto &b){
14            return a.second > b.second;
15        });
16        for(int i=0;i<freq.size();i++){
17            words+=v[i].first;
18        }
19        unordered_map<char,int> mp;
20        for(int i=0;i<words.size();i++){
21            if(mp.size()<8){
22                 if(mp.find(words[i])==mp.end()){
23                    mp[words[i]]=1;
24                 }
25            }
26            else if(mp.size()<16){
27                if(mp.find(words[i])==mp.end()){
28                    mp[words[i]]=2;
29                }
30            }
31            else if(mp.size()<24){
32                if(mp.find(words[i])==mp.end()){
33                    mp[words[i]]=3;
34                }
35            }
36            else{
37                mp[words[i]]=4;
38            }
39        }
40        int ans=0;
41        for(int i=0;i<n;i++){
42            ans+=mp[word[i]];
43        }
44        return ans;
45    }
46};