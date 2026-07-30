// Last updated: 7/30/2026, 12:43:52 PM
1class Solution {
2public:
3    int minimumPushes(string word) {
4        if(word.size()<=8) return word.size();
5        else if(word.size()<=16){
6            int ans=8;
7            int left=word.size()-8;
8            ans+=left*2;
9            return ans;
10        }
11        else if(word.size()<=24){
12            int ans=8*3;
13            int left=word.size()-16;
14            ans+=left*3;
15            return ans;
16        }
17        else{
18            int ans=8*6;
19            int left=word.size()-24;
20            ans+=left*4;
21            return ans;
22        }
23        return 0;
24    }
25};