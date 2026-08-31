// Last updated: 8/31/2026, 4:25:15 PM
// public:   SOLUTION 1
//     int gcd(int a, int b){
//         while(b){
//             int temp=a%b;
//             a=b;
//             b=temp;
//         }
//         return a;
//     }
//     vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
//         int n=nums.size();
//         int m=queries.size();
//         map<pair<int,int>, int> gcdPairs;
//         vector<int> temp;
//         for(int i=0;i<n-1;i++){
//             for(int j=i+1;j<n;j++){
//                 pair<int,int> p={nums[i],nums[j]};
//                 if(gcdPairs.find(p)==gcdPairs.end()){
//                     gcdPairs[p]=gcd(nums[i],nums[j]);
//                 }
//                 temp.push_back(gcdPairs[p]);
//             }
//         }
//         sort(temp.begin(),temp.end());
//         vector<int> answer(m,0);
//         for(int i=0;i<m;i++){
//             answer[i]=temp[queries[i]];
//         }
//         return answer;
//     }
// };



// Solution 2

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int mx = *max_element(nums.begin(), nums.end());

        vector<long long> freq(mx + 1);

        for (int x : nums)
            freq[x]++;

        vector<long long> cnt(mx + 1);

        for (int d = 1; d <= mx; d++) {
            for (int multiple = d; multiple <= mx; multiple += d)
                cnt[d] += freq[multiple];
        }

        vector<long long> exact(mx + 1);

        for (int d = mx; d >= 1; d--) {
            exact[d] = cnt[d] * (cnt[d] - 1) / 2;
            for (int multiple = 2 * d; multiple <= mx; multiple += d)
                exact[d] -= exact[multiple];
        }

        vector<long long> prefix(mx + 1);

        for (int i = 1; i <= mx; i++)
            prefix[i] = prefix[i - 1] + exact[i];

        vector<int> ans;

        for (long long q : queries) {
            int g = lower_bound(prefix.begin(), prefix.end(), q + 1) - prefix.begin();
            ans.push_back(g);
        }

        return ans;
    }
};