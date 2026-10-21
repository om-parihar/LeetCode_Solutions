// Last updated: 10/21/2026, 10:53:17 AM
1class Solution {
2public:
3    string RLE(string a){
4        string ans="";
5        int i=0;
6        while(i<a.size()){
7            int cnt=0;
8            int j=i;
9            while(j<a.size()){
10                if(a[j]==a[i]){
11                    cnt++;
12                    j++;
13                }
14                else{
15                    break;
16                }
17            }
18            ans+=to_string(cnt)+a[i];
19            i=j;
20        }
21        return ans;
22    }
23    string countAndSay(int n) {
24        if(n==1){
25            return "1";
26        }
27        return RLE(countAndSay(n-1));
28    }
29};