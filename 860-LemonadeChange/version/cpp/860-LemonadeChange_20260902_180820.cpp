// Last updated: 9/2/2026, 6:08:20 PM
1class Solution {
2public:
3    bool lemonadeChange(vector<int>& bills) {
4        int five=0,ten=0;
5        for(int i=0;i<bills.size();i++){
6            if(bills[i]==5) five+=1;
7            else if(bills[i]==10){
8                if(five){
9                    five=five-1;
10                    ten+=1;
11                }
12                else{
13                    return false;
14                }
15            }
16            else{
17                if(five && ten){
18                    five-=1;
19                    ten-=1;
20                }
21                else if(five>=3){
22                    five-=3;
23                }
24                else{
25                    return false;
26                }
27            }
28        }
29        return true;
30    }
31};