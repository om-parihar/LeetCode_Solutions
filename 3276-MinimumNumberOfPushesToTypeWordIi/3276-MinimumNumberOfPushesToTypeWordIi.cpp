// Last updated: 8/31/2026, 4:25:28 PM
class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        string words="";
        unordered_map<char, int> freq;

        for(char c : word)
            freq[c]++;

        vector<pair<char,int>> v(freq.begin(), freq.end());

        sort(v.begin(), v.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });
        for(int i=0;i<freq.size();i++){
            words+=v[i].first;
        }
        unordered_map<char,int> mp;
        for(int i=0;i<words.size();i++){
            if(mp.size()<8){
                 if(mp.find(words[i])==mp.end()){
                    mp[words[i]]=1;
                 }
            }
            else if(mp.size()<16){
                if(mp.find(words[i])==mp.end()){
                    mp[words[i]]=2;
                }
            }
            else if(mp.size()<24){
                if(mp.find(words[i])==mp.end()){
                    mp[words[i]]=3;
                }
            }
            else{
                mp[words[i]]=4;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=mp[word[i]];
        }
        return ans;
    }
};