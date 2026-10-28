// Last updated: 10/28/2026, 6:39:25 PM
1class Solution {
2public:
3    int minGroups(vector<vector<int>>& intervals) {
4        int n=intervals.size();
5        vector<int> start;
6        vector<int> end;
7        for(int i=0;i<n;i++){
8            start.push_back(intervals[i][0]);
9            end.push_back(intervals[i][1]);
10        }
11        sort(start.begin(),start.end());
12        sort(end.begin(),end.end());
13        int i=0,j=0;
14        int ans=0;
15        while(i<n){
16            if(start[i]<=end[j]){
17                i++;
18            }
19            else{
20                j++;
21            }
22            ans=max(ans,i-j);
23        }
24        return ans;
25    }
26};