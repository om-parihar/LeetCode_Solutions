// Last updated: 11/22/2026, 4:20:36 PM
1class Solution {
2public:
3    bool checkString(string s) {
4        int cnt=0;
5        for(auto it:s){
6            if(it=='a'){
7                cnt++;
8            }
9        }
10        if(cnt==0) return true;
11        for(auto it:s){
12            if(it=='a'){
13                cnt--;
14            }
15            else{
16                if(it=='b' && cnt) return false;
17                else return true;
18            }
19        }
20        return true;
21    }
22};