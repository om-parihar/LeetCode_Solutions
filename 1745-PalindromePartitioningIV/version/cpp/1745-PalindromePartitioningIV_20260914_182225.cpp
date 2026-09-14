// Last updated: 9/14/2026, 6:22:25 PM
1class Solution {
2public:
3    bool isPalindrome(string& s, int i, int j){
4        while(i<j){
5            if(s[i]!=s[j]) return false;
6            i++;
7            j--;
8        }
9        return true;
10    }
11    bool checkPartitioning(string s) {
12        int n=s.size();
13        for(int i=1;i<n-1;i++){
14            for(int j=i+1;j<n;j++){
15                if(isPalindrome(s,0,i-1) && isPalindrome(s,i,j-1) && isPalindrome(s,j,n-1)){
16                    return true;
17                }
18            }
19        }
20        return false;
21    }
22};