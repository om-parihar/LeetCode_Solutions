// Last updated: 11/18/2026, 6:03:22 PM
1class Solution1 {
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
22
23class Solution {
24public:
25    int lastStoneWeight(vector<int>& stones) {
26        priority_queue<int> pq(stones.begin(),stones.end());
27        while(pq.size()>=2){
28            int h1=pq.top();
29            pq.pop();
30            int h2=pq.top();
31            pq.pop();
32            if(h1!=h2){
33                pq.push(abs(h1-h2));
34            }
35        }
36        if(pq.empty()) return 0;
37        return pq.top();
38    }
39};