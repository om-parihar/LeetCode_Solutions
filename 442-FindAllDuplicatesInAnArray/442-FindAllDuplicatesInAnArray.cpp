// Last updated: 7/25/2026, 10:59:36 PM
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int> res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};