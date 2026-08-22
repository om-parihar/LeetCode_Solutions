// Last updated: 8/22/2026, 11:08:52 AM
1class Solution {
2public:
3    bool checkDivisibility(int n) {
4        int sum=0;
5        int cpy=n;
6        int product=1;
7        while(cpy){
8            int digit=cpy%10;
9            sum+=digit;
10            product*=digit;
11            cpy=cpy/10;
12        }
13        if(n%(sum+product)==0) return true;
14        return false;
15    }
16};