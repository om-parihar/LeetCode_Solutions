// Last updated: 7/25/2026, 10:56:43 PM
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       int n=nums.size();
       vector<int> ans(n);
       int posidx=0,negidx=1;
       for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans[posidx]=nums[i];
                posidx+=2;
            }
            else{
                ans[negidx]=nums[i];
                negidx+=2;
            }
       }
    return ans;

       
       
        // int n=nums.size();
        // vector<int> neg;
        // vector<int> pos;
        // vector<int> ans;
        // for(int i=0;i<n;i++){
        //     if(nums[i]<0){
        //         neg.push_back(nums[i]);
        //     }
        //     else{
        //         pos.push_back(nums[i]);
        //     }
        // }
        // for(int i=0;i<pos.size();i++){
        //     ans.push_back(pos[i]);
        //     ans.push_back(neg[i]);
        // }
        // return ans;
    }
};