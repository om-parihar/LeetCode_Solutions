// Last updated: 7/25/2026, 11:01:36 PM
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> st(nums.begin(),nums.end());
        int maxLen=0;
        for(auto x: st){
            if(st.find(x-1)==st.end()){
                int curr=x;
                int cnt=1;
                while(st.find(curr+1)!=st.end()){
                    curr++;
                    cnt++;
                }
                maxLen=max(maxLen,cnt);
            }
        }
        return maxLen;
    }
};