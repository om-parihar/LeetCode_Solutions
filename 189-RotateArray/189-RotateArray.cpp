// Last updated: 7/25/2026, 11:01:01 PM
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // stack<int>st1;
        // stack<int>st2;
        // while(k){
        //     for(int i=0;i<nums.size();i++){
        //         st1.push(nums[i]);
        //     }
        //     nums[0]=st1.top();
        //     st1.pop();
        //     while(!st1.empty()){
        //         st2.push(st1.top());
        //         st1.pop();
        //     }
        //     int i=1;
        //     while(!st2.empty()){
        //         nums[i]=st2.top();
        //         st2.pop();
        //         i++;
        //     }
        //     k--;
        // }
        int n=nums.size();
        k=k%n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};