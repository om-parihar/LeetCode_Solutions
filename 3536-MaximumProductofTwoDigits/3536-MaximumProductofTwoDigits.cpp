// Last updated: 7/25/2026, 11:15:54 PM
1class Solution {
2public:
3    int maxProduct(int n) {
4        int fLar=0;
5        int sLar;
6        while(n){
7            int num=n%10;
8            if(num>=fLar){
9                sLar=fLar;
10                fLar=num;
11            }
12            else if(num>sLar){
13                sLar=num;
14            }
15            n=n/10;
16        }
17        return sLar*fLar;
18    }
19};