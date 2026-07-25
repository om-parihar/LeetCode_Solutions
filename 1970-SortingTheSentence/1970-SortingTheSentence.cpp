// Last updated: 7/25/2026, 10:56:58 PM
class Solution {
public:
    string sortSentence(string s) {
        vector<string> ans(10);
        string temp;
        int cnt=0;
        int index=0;
        while(index<s.size()){
            if(s[index]==' '){
                int pos=temp[temp.size()-1]-'0';
                temp.pop_back();
                ans[pos]=temp;
                temp.clear();
                cnt++;
            }
            else{
                temp+=s[index];
            }
                index++;
        }
        int pos=temp[temp.size()-1]-'0';
                temp.pop_back();
                ans[pos]=temp;
                temp.clear();
                cnt++;
        for(int i=1;i<=cnt;i++){
            temp+=ans[i];
            temp+=" ";
        }
        temp.pop_back();
        return temp;
    }
};