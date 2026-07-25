// Last updated: 7/25/2026, 10:57:40 PM
class Solution {
public:
    string defangIPaddr(string address) {
        int n=address.size();
        string ans;
        int i=0;
        while(i<n){
            if(address[i]=='.'){
                ans=ans+"[.]";
            }
            else{
                ans=ans+address[i];
            }
            i++;
        }
        return ans;
    }
};