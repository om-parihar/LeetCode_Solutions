// Last updated: 7/25/2026, 11:01:13 PM
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res="";
        while(columnNumber>0){
            columnNumber--;
            char c='A'+(columnNumber%26);
            res=c+res;
            columnNumber=columnNumber/26;
        }
        return res;
    }
};