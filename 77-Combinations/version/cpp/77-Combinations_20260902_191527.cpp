// Last updated: 9/2/2026, 7:15:27 PM
1class Solution {
2public:
3    void count(int n, int k, vector<int> & temp, vector<vector<int>> & all){
4        if(k==0){
5            all.push_back(temp);
6            return;
7        }
8        if(n==0){
9            return;
10        }
11        temp.push_back(n);
12        count(n-1,k-1,temp,all);
13        temp.pop_back();
14        count(n-1,k,temp,all);
15}
16    vector<vector<int>> combine(int n, int k) {
17        vector<int> temp;
18        vector<vector<int>> all;
19        count(n,k,temp,all);
20        return all;
21    }
22};