// Last updated: 10/24/2026, 11:53:46 PM
1class Solution {
2public:
3    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
4        int n=intervals.size();
5        int cnt=0;
6        sort(intervals.begin(),intervals.end(),[](vector<int> a, vector<int> b){
7            return a[1]<b[1];
8        });
9        int end=intervals[0][1];
10        for(int i=1;i<n;i++){
11            if(intervals[i][0]<end){
12                cnt++;
13            }
14            else{
15                end=intervals[i][1];
16            }
17        }
18        return cnt;
19    }
20};