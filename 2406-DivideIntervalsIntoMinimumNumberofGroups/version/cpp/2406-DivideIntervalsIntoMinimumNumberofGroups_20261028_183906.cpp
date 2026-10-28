// Last updated: 10/28/2026, 6:39:06 PM
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
15        int temp=0;
16        while(i<n){
17            if(start[i]<=end[j]){
18                temp+=1;
19                i++;
20            }
21            else{
22                temp-=1;
23                j++;
24            }
25            ans=max(ans,temp);
26        }
27        return ans;
28    }
29};