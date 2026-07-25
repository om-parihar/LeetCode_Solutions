// Last updated: 7/25/2026, 10:59:25 PM
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=0;i<n;i++){
            int j=0;
            while(nums1[i]!=nums2[j]){
                j++;
            }
            for(int k = j + 1; k < m; k++) {
                if(nums2[k] > nums1[i]) {
                    ans[i] = nums2[k];
                    break;
                }
            }
            st.push(j);
        }
        return ans;
    }
};