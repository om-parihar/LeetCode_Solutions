// Last updated: 9/8/2026, 4:06:46 PM
1class Solution {
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