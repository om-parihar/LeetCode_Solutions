// Last updated: 7/25/2026, 11:01:16 PM
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        vector<int> fre;
        fre=nums;
        sort(fre.begin(),fre.end());
        int a=fre[fre.size()-1];
        int idx=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==a){
                idx=i;
                break;
            }
        }
        return idx;
    }
};