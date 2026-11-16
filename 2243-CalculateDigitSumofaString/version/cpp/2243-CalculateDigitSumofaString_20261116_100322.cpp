// Last updated: 11/16/2026, 10:03:22 AM
1class Solution {
2public:
3    string digitSum(string s, int k) {
4        int n=s.size();
5        while(s.size()>k){
6            string x="";
7            for(int i=0;i<s.size();i+=k){
8                int sum=0;
9                for(int j=i;j<min(i+k,(int)s.size());j++){
10                    sum+=s[j]-'0';
11                }
12                x+=to_string(sum);
13            }
14            s=x;
15        }
16        return s;
17    }
18};