// Last updated: 7/25/2026, 11:00:47 PM
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int,vector<int>, greater<int>> p;
        for(int i=0;i<k;i++){
            p.push(nums[i]);
        }
        for(int i=k;i<n;i++){
            if(nums[i]>p.top()){
                p.pop();
                p.push(nums[i]);
            }
        }
        return p.top();
    }
};