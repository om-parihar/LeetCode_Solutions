// Last updated: 7/25/2026, 10:58:59 PM
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        double maxsum=sum;
        for(int i=k;i<n;i++){
            sum+=nums[i]-nums[i-k];
            if(maxsum<sum){
                maxsum=sum;
            }
        }
        return maxsum/k;
    }
};