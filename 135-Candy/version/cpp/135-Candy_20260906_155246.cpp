// Last updated: 9/6/2026, 3:52:46 PM
1class Solution {
2public:
3    int candy(vector<int>& ratings) {
4        int n=ratings.size();
5        vector<int> leftNeighbours(n,1);
6        vector<int> rightNeighbours(n,1);
7        for(int i=1;i<n;i++){
8            if(ratings[i-1]<ratings[i]){
9                leftNeighbours[i]=leftNeighbours[i-1]+1;
10            }
11        }
12        for(int i=n-2;i>=0;i--){
13            if(ratings[i+1]<ratings[i]){
14                rightNeighbours[i]=rightNeighbours[i+1]+1;
15            }
16        }
17        int ans=0;
18        for(int i=0;i<n;i++){
19            ans+=max(leftNeighbours[i],rightNeighbours[i]);
20        }
21        return ans;
22    }
23};