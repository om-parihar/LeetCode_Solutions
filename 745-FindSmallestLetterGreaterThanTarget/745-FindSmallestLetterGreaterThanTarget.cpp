// Last updated: 7/25/2026, 10:58:47 PM
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        for(int i=0;i<n;i++){
            if(letters[i]>target){
                return letters[i];
            }
        }
        return letters[0];
    }
};