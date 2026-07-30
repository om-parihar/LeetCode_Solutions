// Last updated: 7/30/2026, 12:52:27 PM
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int fmax=0;
        int smax=0;
        for(int it:nums){
            if(it>=fmax){
                smax=fmax;
                fmax=it;
            }
            else if(it>=smax){
                smax=it;
            }
        }
        return ((fmax-1)*(smax-1));
    }
};