// Last updated: 7/25/2026, 10:56:50 PM
class Solution {
public:
    int gcd(int a,int b){
        while(b){
            int temp=a%b;
            a=b;
            b=temp;
        }
        return a;
    }
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=nums[0];
        int j=nums[nums.size()-1];
        return gcd(i,j);
    }
};