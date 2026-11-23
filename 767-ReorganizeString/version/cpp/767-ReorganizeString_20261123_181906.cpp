// Last updated: 11/23/2026, 6:19:06 PM
1class Solution {
2public:
3    string reorganizeString(string s) {
4        int n=s.size();
5        string ans="";
6        unordered_map<char,int> mp;
7        for(int i=0;i<n;i++){
8            mp[s[i]]++;
9        }
10        priority_queue<pair<int,char>> pq;
11        for(auto it:mp){
12            pq.push({it.second,it.first});
13        }
14        pair<int,char> prev(0,'#');
15        while(!pq.empty()){
16            char a=pq.top().second;
17            int cnt=pq.top().first;
18            ans+=a;
19            pq.pop();
20            if(prev.first>0) pq.push(prev);
21            prev={cnt-1,a};
22        }        
23        if(prev.first>0) return "";
24        return ans;
25    }
26};