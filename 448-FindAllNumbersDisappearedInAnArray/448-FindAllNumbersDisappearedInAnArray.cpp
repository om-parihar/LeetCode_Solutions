// Last updated: 7/25/2026, 10:59:34 PM
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,0);
        vector<int> fre;
        for(int i=0;i<n;i++){
            res[nums[i]-1]++;
        }
        for(int i=0;i<n;i++){
            if(res[i]==0){
                fre.push_back(i+1);
            }
        }
        return fre;
    }
};