// Last updated: 7/25/2026, 11:00:53 PM
class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        vector<bool> Isprime(n,true);
        Isprime[0]=Isprime[1]=false;
        for(int i=2;i*i<n;i++){
            if(Isprime[i]){
                for(int j=i*i;j<n;j+=i){
                    Isprime[j]=false;
                }
            }
        }
        int prime = 0;
        for (int i = 2; i < n; i++) {
            if (Isprime[i]) {
            prime++;
            }
        }
        return prime;
    }
};