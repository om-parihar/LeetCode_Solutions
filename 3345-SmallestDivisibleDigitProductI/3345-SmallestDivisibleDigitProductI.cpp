// Last updated: 8/6/2026, 10:10:31 AM
1class Solution {
2public:
3    int smallestNumber(int n, int t) {
4        while(true){
5            int x=n;
6            int prod=1;
7            while(x>0){
8                prod*=(x%10);
9                x=x/10;
10            }
11            if(prod%t==0){
12                return n;
13            }
14            n++;
15        }
16        return 0;
17    }
18};