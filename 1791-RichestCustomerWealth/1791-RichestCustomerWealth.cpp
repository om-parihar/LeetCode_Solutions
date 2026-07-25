// Last updated: 7/25/2026, 10:57:10 PM
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        if(accounts.empty()||accounts[0].empty()) return 0;
        int a=accounts.size();
        int b=accounts[0].size();
        int mx=0;
        for(int i=0;i<a;i++){
            int sum=0;
            for(int j=0;j<b;j++){
                sum+=accounts[i][j];
            }
            mx=max(sum,mx);
        }
        return mx;
    }
};