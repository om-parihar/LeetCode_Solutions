// Last updated: 7/25/2026, 11:02:57 PM
// class Solution {
// public:
//     void combi(vector<int> &ds, vector<vector<int>> &ans, vector<int> &nums, int freq[]){
//         if(ds.size()==nums.size()){
//             ans.push_back(ds);
//             return;
//         }
//         for(int i=0;i<nums.size();i++){
//             if(!freq[i]){
//                 freq[i]=1;
//                 ds.push_back(nums[i]);
//                 combi(ds,ans,nums,freq);
//                 freq[i]=0;
//                 ds.pop_back();
//             }
//         }
//     }

//     void nextPermutation(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> aa;
//         aa=nums;
//         sort(nums.begin(),nums.end());
//         vector<int> ds;
//         vector<vector<int>> ans;
//         int freq[n];
//         for(int i=0;i<n;i++) freq[i]=0;
//         int i=0;
//         combi(ds, ans, nums, freq);
//         for(int i=0;i<ans.size();i++){
//             if(ans[i]==aa){
//                 if(i+1<ans.size()){
//                     nums=ans[i+1];
//                 }
//                 else{
//                     nums=ans[0];
//                 }
//             }
//         }
//     }
// };

// class Solution{
// public:
//     void nextPermutation(vector<int> &nums){
//         next_permutation(nums.begin(),nums.end());
//     }
// };

class Solution{
public:
    void nextPermutation(vector<int> &nums){
        int n=nums.size();
        int idx=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx=i;
                break;
            }
        }
        if(idx==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]>nums[idx]){
                swap(nums[i],nums[idx]);
                break;
            }
        }
        reverse(nums.begin()+idx+1,nums.end());      
    }
};