// Last updated: 10/17/2026, 6:49:14 PM
1class Solution {
2public:
3    vector<vector<int>> generateMatrix(int n) {
4            int left=0,right=n-1;
5            int top=0,bottom=n-1;
6            vector<vector<int>> ans(n,vector<int>(n));
7            int val=1;
8        while(left<=right && top<=bottom){
9                for(int i=left;i<=right;i++){
10                    ans[top][i]=val++;
11                }
12                top++;
13                if(top<=bottom){
14                    for(int j=top;j<=bottom;j++){
15                        ans[j][right]=val++;
16                    }
17                    right--;
18                }
19                if(top<=bottom){
20                    for(int i=right;i>=left;i--){
21                        ans[bottom][i]=val++;
22                    }
23                    bottom--;
24                }
25                if(left<=right){
26                    for(int j=bottom;j>=top;j--){
27                        ans[j][left]=val++;
28                    }
29                    left++;
30                }
31        }
32        return ans;
33    }
34};