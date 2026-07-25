// Last updated: 7/25/2026, 11:01:44 PM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minPrice=INT_MAX;
        int maxProfit=0;
        for(int i=0;i<n;i++){
            if(prices[i]<minPrice){
                minPrice=prices[i];
            }
            else{
                maxProfit=max(maxProfit,abs(minPrice-prices[i]));
            }
        }
        return maxProfit;
    }
};