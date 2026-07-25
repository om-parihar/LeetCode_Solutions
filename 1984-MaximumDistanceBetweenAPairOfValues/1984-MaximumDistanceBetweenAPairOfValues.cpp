// Last updated: 7/25/2026, 10:56:56 PM
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int i=0,j=0;
        int maxdis=0;
        while(i<n && j<m){
            if(nums1[i]<=nums2[j]){
                maxdis=max(maxdis,j-i);
                j++;
            }
            else{
                i++;
            }
        }
        return maxdis;
    }
};