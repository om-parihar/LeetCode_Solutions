// Last updated: 11/18/2026, 5:54:12 PM
1class Solution {
2public:
3    int find(vector<int>& stones){
4        int mx=max_element(stones.begin(),stones.end())-stones.begin();
5        int ans=stones[mx];
6        swap(stones[stones.size()-1],stones[mx]);
7        stones.pop_back();
8        return ans;
9    }
10    int lastStoneWeight(vector<int>& stones) {
11        while(stones.size()>=2){
12            int h1=find(stones);
13            int h2=find(stones);
14            if(h1!=h2){
15                stones.push_back((h1-h2));
16            }
17        }
18        if(stones.empty()) return 0;
19        return stones[0];
20    }
21};