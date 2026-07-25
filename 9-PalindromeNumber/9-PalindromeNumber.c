// Last updated: 7/25/2026, 11:03:22 PM
bool isPalindrome(int x) {
    if (x < 0) return false;
    long long sum=0;
    int n=x;
    while(x!=0){
        int rem=x%10;
        if(sum>INT_MAX/10) return false;
        sum=sum*10+rem;
        x=x/10;
    }
    return sum==n;
}