// Last updated: 8/14/2026, 3:03:19 PM
1class Solution {
2public:
3    int findContentChildren(vector<int>& g, vector<int>& s) {
4        sort(g.begin(),g.end());
5        sort(s.begin(),s.end());
6        int a=g.size();
7        int b=s.size();
8        int sum=0;
9        int i=0;
10        int j=0;
11        while(i<a && j<b){
12            if(g[i]<=s[j]){
13                sum++;
14                i++;
15            }
16            j++;
17        }
18        return sum;
19    }
20};