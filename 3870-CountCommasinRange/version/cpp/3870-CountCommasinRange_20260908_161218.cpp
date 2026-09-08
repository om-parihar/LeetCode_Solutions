// Last updated: 9/8/2026, 4:12:18 PM
1class Solution1 {
2public:
3    int countCommas(int n) {
4        string x=to_string(n);
5        int a=x.size();
6        if(a<4) return 0;
7        int cnt=0;
8        int b=1000;
9        for(int c=b;c<=n;c++){
10            if(to_string(c).size()<7){
11                cnt+=1;
12            }
13            else if(to_string(c).size()<10){
14                cnt+=2;
15            }
16            else{
17                cnt+=3;
18            }
19        }
20        return cnt;
21    }
22};
23
24
25class Solution {
26public:
27    int countCommas(int n) {
28        int ans = 0;
29
30        if (n >= 1000)
31            ans += n - 999;
32
33        if (n >= 1000000)
34            ans += n - 999999;
35
36        if (n >= 1000000000)
37            ans += n - 999999999;
38
39        return ans;
40    }
41};