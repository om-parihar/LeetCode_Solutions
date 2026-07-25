// Last updated: 7/25/2026, 11:02:09 PM
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len=(n+m);
        int gap=(len/2)+(len%2);
        while(gap>0){
            int left=0;
            int right=left+gap;
            while(right<len){
                if(left<m && right>=m){
                    if(nums1[left]>nums2[right-m]){
                        swap(nums1[left],nums2[right-m]);
                    }
                }
                else if(left>=m){
                    if(nums2[left-m]>nums2[right-m]){
                        swap(nums2[left-m],nums2[right-m]);
                    }
                }
                else{
                    if(nums1[left]>nums1[right]){
                        swap(nums1[left],nums1[right]);
                    }
                }
                left++;
                right++;
            }
            if(gap==1) break;
            gap=(gap/2)+(gap%2);
        }
        int idx=0;
        for(int i=m;i<m+n;i++){
            nums1[i]=nums2[idx];
            idx++;
        }
    }
};