// Last updated: 7/25/2026, 10:56:09 PM
class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int,int>fre;
        for(int num: nums){
            fre[num]++;
        }
        long long result=0;
        for(auto& pair : fre){
            int val=pair.first;
            int f=pair.second;
            if(f%k==0){
                result+=(long long)val*f;
            }
        }
        return result;
    }
};