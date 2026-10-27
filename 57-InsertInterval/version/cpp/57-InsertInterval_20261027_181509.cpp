// Last updated: 10/27/2026, 6:15:09 PM
1class Solution {
2public:
3    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
4        int n=intervals.size();
5        vector<vector<int>> ans;
6        int i=0;
7        if(n==0){
8            ans.push_back(newInterval);
9            return ans;
10        }
11        int flg=0;
12        while(i<n){
13            if(intervals[i][1]<newInterval[0]){
14                ans.push_back(intervals[i]);
15                i++;
16            }
17            else{
18                int start=min(intervals[i][0],newInterval[0]);
19                int end=newInterval[1];
20                int j=i;
21
22                while(j<n && intervals[j][0]<=end){
23                    end=max(end,intervals[j][1]);
24                    j++;
25                }
26
27                ans.push_back({start,end});
28                i=j;
29                flg=1;
30                break;
31            }
32        }
33        if(i==n && flg==0){
34            ans.push_back(newInterval);
35        }
36
37        while(i<n){
38            ans.push_back(intervals[i]);
39            i++;
40        }
41
42        return ans;
43    }
44};