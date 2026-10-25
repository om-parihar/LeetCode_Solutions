// Last updated: 10/25/2026, 9:50:02 PM
1class Solution {
2public:
3    vector<int> finalPrices(vector<int>& prices) {
4        int n=prices.size();
5        vector<int> ans;
6        for(int i=0;i<n;i++){
7            int val=prices[i];
8            for(int j=i+1;j<n;j++){
9                if(prices[j]<=prices[i]){
10                    val=prices[i]-prices[j];
11                    break;
12                }
13            }
14            ans.push_back(val);
15        }
16        return ans;
17    }
18};