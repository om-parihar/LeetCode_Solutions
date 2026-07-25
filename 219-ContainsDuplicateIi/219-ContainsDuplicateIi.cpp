// Last updated: 7/25/2026, 11:00:43 PM
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> x; 
        int i=0;
        while(i<nums.size()) {
            if(x.count(nums[i])) {
                return true; 
            }
            x.insert(nums[i]);
            if(i>=k){
                x.erase(nums[i - k]);
            }
            i++;
        }
        return false;
    }
};