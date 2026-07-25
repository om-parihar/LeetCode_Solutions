// Last updated: 7/25/2026, 11:02:54 PM
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int c=0;
        int b=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                c=i;
                b=b+1;
                break;
            }

        }
        int t=0;
        if(b!=0){
            for(int j=c;j<nums.size();j++){
                if(nums[j]==target){
                    t=j;
                }
                  
                
            }
            return {c,t};
        
        }

        else{
            return {-1,-1};
        }



    }
};