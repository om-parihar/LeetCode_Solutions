// Last updated: 10/29/2026, 10:49:59 PM
1class Solution {
2public:
3    int bulbSwitch(int n) {
4        int ans=0;
5        for(int i=1;i*i<=n;i++){
6            ans++;
7        }
8        return ans;
9    }
10};