// Last updated: 7/25/2026, 10:57:38 PM
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int m=arr2.size();
        int a=0;
        vector<int> ans;
        while(a!=m){
            for(int i=0;i<n;i++){
                if(arr1[i]==arr2[a]){
                    ans.push_back(arr1[i]);
                }
            }
            a++;
        }
        vector<int> odds;
        for(int i=0;i<n;i++){
            int flg=0;
            for(int j=0;j<m;j++){
                if(arr1[i]!=arr2[j]){
                    flg++;   
                }
            }
            if(flg==m){
                odds.push_back(arr1[i]);
            }
        }
        sort(odds.begin(),odds.end());
        for(int i=0;i<odds.size();i++){
            ans.push_back(odds[i]);
        }
        return ans;
    }
};