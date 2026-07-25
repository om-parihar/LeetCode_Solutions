// Last updated: 7/25/2026, 10:58:55 PM
#include<bits/stdc++.h>
class Solution {
public:
    int calPoints(vector<string>& operations) {
       vector<int> res;
        for(string op: operations){
            if(op=="C"){
                if(!res.empty()) res.pop_back(); 
            } else if(op=="D"){
                if(!res.empty()) res.push_back(res.back()*2); 
            } else if(op=="+"){
                if(res.size()>=2){
                    res.push_back(res[res.size()-1]+res[res.size()-2]); 
                }
            }
            else{
                res.push_back(stoi(op)); 
            }
        }
        int sum=0;
        for(int score: res){
            sum+=score;
        }
        return sum;
    }
};