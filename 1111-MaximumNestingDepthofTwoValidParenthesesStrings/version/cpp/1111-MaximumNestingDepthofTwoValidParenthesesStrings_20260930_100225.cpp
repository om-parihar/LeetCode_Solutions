// Last updated: 9/30/2026, 10:02:25 AM
1class Solution {
2public:
3    vector<int> maxDepthAfterSplit(string seq) {
4        int n=seq.size();
5        int d=0;
6        vector<int> ans;
7        for(char c: seq){
8            if(c=='('){
9                d++;
10                ans.push_back(d%2);
11            }
12            else{
13                ans.push_back(d%2);
14                d--;
15            }
16        }
17        return ans;
18    }
19};