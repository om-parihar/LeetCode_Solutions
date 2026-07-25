// Last updated: 7/25/2026, 10:57:28 PM
class Solution {
private:
    bool zero(int num){
        while(num>0){
            if(num%10==0) return false;
            num=num/10;
        }
        return true;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        int b=0;
        for(int a=1;a<n;a++){
            b=n-a;
            if(zero(a) && zero(b)){
                return {a,b};
            }
        }
        return {};
    }
};