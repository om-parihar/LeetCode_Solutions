// Last updated: 7/25/2026, 11:01:23 PM
class Solution {
public:
    string reverseWords(string s) {
        stack<char>st1;
        int n=s.size();
        for(char c:s){
            st1.push(c);
        }
        string a="";
        string b="";
        while(!st1.empty()){
            char ch=st1.top();
            st1.pop();
            if(ch==' '){
                if(!b.empty()){
                    a+=b+" ";
                    b="";
                }
            }
            else{
                b=ch+b;
            }
        }
        if(!b.empty()){
            a+=b;
        }
        else if(!a.empty()){
        a.pop_back();
        }

        return a;
    }
};