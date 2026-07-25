// Last updated: 7/25/2026, 10:59:51 PM
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int a=ransomNote.length();
        int b=magazine.length();
        int i=0;
        int j=0;
        int cnt=0;
        int n=ransomNote.size();
        sort(ransomNote.begin(),ransomNote.end());
        sort(magazine.begin(),magazine.end());
        while(i<a && j<b){
            if(ransomNote[i]==magazine[j]){
                i++;
                j++;
            }
            else if (ransomNote[i]>magazine[j]){
                j++;
            }
            else return false;
            
        }
        return i==n;
    }
};