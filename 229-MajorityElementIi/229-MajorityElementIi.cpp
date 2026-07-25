// Last updated: 7/25/2026, 11:00:36 PM
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int candidate1=0;
        int candidate2=0;
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<n;i++){
             int x=nums[i];
             if(x==candidate1){
                cnt1++;
             }
             else if(x==candidate2){
                cnt2++;
             }
             else if(cnt1==0){
                candidate1=x;
                cnt1=1;
             }
             else if(cnt2==0){
                candidate2=x;
                cnt2=1;
             }
             else{
                cnt1--;
                cnt2--;
             }
        }
        cnt1=0;
        cnt2=0;
        for(int x:nums){
            if(x==candidate1) cnt1++;
            if(x==candidate2) cnt2++;
        }
        vector<int> ans;
        if(cnt1>n/3) ans.push_back(candidate1);
        if(candidate1!=candidate2 && cnt2>n/3) ans.push_back(candidate2);
        return ans;
    }
};