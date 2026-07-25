// Last updated: 7/25/2026, 11:00:13 PM
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s=1;
        long long int e=n;
        int a=0;
        while(s<=e){
            long long int mid=(s+e)/2;
            if(isBadVersion(mid)){
                a=mid;

                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return a;
    }
};