// Last updated: 7/25/2026, 11:09:00 PM
1class Solution {
2public:
3    int maxProduct(int n) {
4        int mx=INT_MIN;
5        string a=to_string(n);
6        for(int i=0;i<a.size();i++){
7            for(int j=i+1;j<a.size();j++){
8                int m=((a[i]-'0')*(a[j]-'0'));
9                if(m>mx){
10                    mx=m;
11                }
12            }
13        }
14        return mx;
15    }
16};