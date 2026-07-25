// Last updated: 7/25/2026, 11:00:17 PM
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;
        if(nums.size()<2) return res;
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<nums.size()){
            if(i==nums.size()-1 || nums[i]!=nums[i+1]){
                res.push_back(nums[i]);
                i++;
            }
            else{
                i=i+2;
            }
        }
        return res;
    }
};