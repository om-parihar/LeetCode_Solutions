// Last updated: 7/25/2026, 10:58:09 PM
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        mp[0]=1;
        int total=0;
        int sum=0;
        int rem=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            rem=sum%k;
            if(rem<0){
                rem+=k;
            }
            if(mp.count(rem)){
                total+=mp[rem];
                mp[rem]++;
            }
            else{
                mp[rem]=1;
            }
        }
        return total;
    }
};