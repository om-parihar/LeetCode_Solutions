// Last updated: 9/24/2026, 10:04:34 AM
1class Solution {
2public:
3    unordered_map<int,int> mp;
4    int numTrees(int n) {
5        if(n<=1) return 1;
6        if(mp[n]) return mp[n];
7        int total=0;
8        for(int i=1;i<=n;i++){
9            int left=numTrees(i-1);
10            int right=numTrees(n-i);
11            total+=left*right;
12        }
13        mp[n]=total;
14        return mp[n];
15    }
16};