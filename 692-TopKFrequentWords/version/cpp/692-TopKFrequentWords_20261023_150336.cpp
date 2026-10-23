// Last updated: 10/23/2026, 3:03:36 PM
1class Solution1 {
2public:
3    vector<string> topKFrequent(vector<string>& words, int k) {
4        int n=words.size();
5        unordered_map<string,int> mp;
6        for(int i=0;i<n;i++){
7            if(mp.find(words[i])==mp.end()){
8                mp[words[i]]++;
9            }
10            else{
11                mp[words[i]]=mp[words[i]]+1;
12            }
13        }
14        priority_queue<pair<int,string>> pq;
15        vector<string> ans;
16        for(auto it: mp){
17            pq.push({it.second,it.first});
18        }
19        while(k && !pq.empty()){
20            int x=pq.top().first;
21            vector<string> temp;
22            while(!pq.empty() && pq.top().first==x){
23                temp.push_back(pq.top().second);
24                pq.pop();
25            }
26            sort(temp.begin(),temp.end());
27            int y=0;
28            while(k && y<temp.size()){
29                k--;
30                ans.push_back(temp[y]);
31                y++;
32            }
33        }
34        return ans;
35    }
36};
37
38class Solution {
39public:
40    vector<string> topKFrequent(vector<string>& words, int k) {
41        int n=words.size();
42        unordered_map<string,int> mp;
43        for(int i=0;i<n;i++){
44            if(mp.find(words[i])==mp.end()){
45                mp[words[i]]=1;
46            }
47            else{
48                mp[words[i]]=mp[words[i]]+1;
49            }
50        }
51        priority_queue<pair<int,string>> pq;
52        for(auto it: mp){
53            pq.push({-it.second,it.first});
54            if(pq.size()>k){
55                pq.pop();
56            }
57        }
58        vector<string> ans(k);
59        while(!pq.empty()){
60            ans[k-1]=pq.top().second;
61            pq.pop();
62            k--;
63        }
64        return ans;
65    }
66};