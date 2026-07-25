// Last updated: 7/25/2026, 11:03:31 PM
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> res;
        int i=0,j=0;
        while(i<n && j<m){
            if(nums1[i]<=nums2[j]){
                res.push_back(nums1[i]);
                i++;
            }
            else{
                res.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n){
            res.push_back(nums1[i]);
            i++;
        }
        while(j<m){
            res.push_back(nums2[j]);
            j++;
        }
        int b=res.size();
        if(b%2==0){
            double k=res[(b/2)-1];
            double c=res[(b/2)];
            return (k+c)/2.0;
        }
        else{
            return res[b/2];
        }
        return res[0];
    }
};