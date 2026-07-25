// Last updated: 7/25/2026, 11:03:21 PM
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int left=0;
        int right=n-1;
        int max_area=0;
        while(left<right){
            int current=min(height[left],height[right])*(right - left);
            max_area=max(max_area,current);
            if(height[left]<height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max_area;
    }
};