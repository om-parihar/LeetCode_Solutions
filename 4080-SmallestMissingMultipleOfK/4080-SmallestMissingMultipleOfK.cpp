// Last updated: 8/31/2026, 4:24:48 PM
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int ans=k;
        unordered_set<int> st(nums.begin(),nums.end());
        while(st.count(ans)){
            ans+=k;
        }
        return ans;
    }
};

class Solution1 {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int ans=k;
        while(1){
            int flg=0;
            for(auto it: nums){
                if(it==ans){
                    flg=1;
                    break;
                }
            }
            if(flg==0){
                break;
            }
            ans+=k;
        }
        return ans;
    }
};