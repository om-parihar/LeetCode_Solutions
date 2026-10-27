// Last updated: 10/27/2026, 4:23:31 PM
1class Solution {
2public:
3    vector<string> createGrid(int m, int n) {
4        vector<string> arr;
5        for(int i=0;i<m;i++){
6            string temp="";
7            for(int j=0;j<n;j++){
8                if(i==0 || j==n-1){
9                    temp+='.';
10                }
11                else{
12                    temp+='#';
13                }
14            }
15            arr.push_back(temp);
16        }
17        return arr;
18    }
19};