// Last updated: 7/25/2026, 11:03:00 PM
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        while (i<nums.size()){
            if(nums[i]==val) {
                nums.erase(nums.begin()+i);
            }else{
            i++;
            }
        }
        return nums.size();
    }
};