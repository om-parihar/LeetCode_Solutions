// Last updated: 8/19/2026, 7:43:21 PM
1class Solution {
2public:
3    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
4        unordered_map<int,unordered_set<int>> mp;
5        for(auto &it: reservedSeats){
6            mp[it[0]].insert(it[1]);
7        }
8        int cnt=(n-mp.size())*2;
9        for(auto &[row, seats]:mp){
10            bool left=true;
11            bool middle=true;
12            bool right=true;
13            for(int x=2;x<=5;x++){
14                if(seats.count(x)){
15                    left=false;
16                    break;
17                }
18            }
19            for(int x=4;x<=7;x++){
20                if(seats.count(x)){
21                    middle=false;
22                    break;
23                }
24            }
25            for(int x=6;x<=9;x++){
26                if(seats.count(x)){
27                    right=false;
28                    break;
29                }
30            }
31            if(left&&right){
32                cnt+=2;
33            }
34            else if(left||middle||right){
35                cnt+=1;
36            }
37        }
38        return cnt;
39    }
40};