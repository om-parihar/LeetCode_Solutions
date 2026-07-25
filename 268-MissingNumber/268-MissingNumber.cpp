// Last updated: 7/25/2026, 11:00:14 PM
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(n==1 && nums[n-1]==0) return nums[n-1]+1;
        if(n==1 && nums[n-1]==1) return nums[n-1]-1;
        if(nums[0]!=0) return nums[0]-1;
        int a=1;
        int i=0;
        int j=1;
        while(i<j && j!=n){
            int b=nums[j];
            if(nums[i]+1==b){
                a++;
                i++;
                j++;
            }
            else{
                a=i+1;
                break;
            }
        }
        if(a==n){
            return nums[n-1]+1;
        }
        return a;
    }
};