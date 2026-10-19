// Last updated: 10/19/2026, 9:30:28 AM
1class Solution {
2public:
3    int leastInterval(vector<char>& tasks, int n) {
4        int m=tasks.size();
5        vector<int> freq(26,0);
6        priority_queue<int> pq;
7        for(int i=0;i<m;i++){
8            int num=tasks[i]-'A';
9            freq[num]++;
10        }
11        for(int i=0;i<26;i++){
12            if(freq[i]>0){
13                pq.push(freq[i]);
14            }
15        }
16        int cnt=0;
17        while(!pq.empty()){
18            vector<int> temp;
19            for(int i=1;i<=n+1;i++){
20                if(!pq.empty()){
21                    int fre=pq.top();
22                    pq.pop();
23                    fre--;
24                    temp.push_back(fre);
25                }
26            }
27            for(int &f:temp){
28                if(f>0){
29                    pq.push(f);
30                }
31            }
32            if(pq.empty()){
33                cnt+=temp.size();
34            }else{
35                cnt+=n+1;
36            }
37        }
38        return cnt;
39    }
40};