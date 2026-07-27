// Last updated: 7/27/2026, 9:50:48 PM
1class Solution {
2public:
3    int distributeCandies(int n, int limit) {
4        int a=min(limit,n);
5        int cnt=0;
6        for(int i=0;i<=a;i++){
7            for(int j=0;j<=a;j++){
8                int c=n-(i+j);
9                if(c>=0 && c<=limit) cnt++;
10            }
11        }
12        return cnt;
13    }
14};