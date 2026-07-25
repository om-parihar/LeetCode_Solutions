// Last updated: 7/25/2026, 10:56:08 PM
class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0) return 0;
        string ans;
        long long sum=0;
        string a=to_string(n);
        for(int i=0;i<a.size();i++){
            if(a[i]=='0'){
                continue;
            }
            else{
                sum+=a[i]-'0';
                ans+=a[i];
            }
        }
        long long an=stoi(ans);
        return sum*an;
    }
};