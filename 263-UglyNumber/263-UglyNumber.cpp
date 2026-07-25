// Last updated: 7/25/2026, 11:00:16 PM
class Solution {
public:
    bool isUgly(int num) {
    if (num <= 0) return false;
    int primes[]={2, 3, 5};
    for (int i=0;i<3;i++) {
        while (num%primes[i]==0) {
            num/=primes[i];
        }
    }
    return num==1;
}
};