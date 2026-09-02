// Last updated: 9/2/2026, 10:01:38 AM
1class Solution {
2public:
3    bool uniformArray(vector<int>& nums1) {
4        int n=nums1.size();
5        vector<bool> n1;
6        vector<bool> n2;
7        for(int i=0;i<n;i++){
8            for(int j=0;j<n;j++){
9                if(j!=i){
10                    if((nums1[i]-nums1[j])%2!=0 || nums1[i]%2!=0){
11                        n1.push_back(true);
12                        break;
13                    }
14                }
15            }
16        }
17        for(int i=0;i<n;i++){
18            for(int j=0;j<n;j++){
19                if(j!=i){
20                    if((nums1[i]-nums1[j])%2==0 || nums1[i]%2==0){
21                        n2.push_back(true);
22                        break;
23                    }
24                }
25            }
26        }
27        int cnt1=0,cnt2=0;
28        for(int i=0;i<n;i++){
29            if(true){
30                cnt1++;
31            }
32        }
33        if(cnt1==n) return true;
34        for(int i=0;i<n;i++){
35            if(true){
36                cnt2++;
37            }
38        }
39        if(cnt2==n) return true;
40        return false;
41    }
42};