// Last updated: 10/19/2026, 11:52:16 AM
1class Solution {
2public:
3    long long taskSchedulerII(vector<int>& tasks, int space) {
4        int n=tasks.size();
5        unordered_map<long long,long long> mp;
6        long long currentday=0;
7        for(int i=0;i<n;i++){
8            currentday++;
9            if(mp.find(tasks[i])!=mp.end()){
10                long long val=mp[tasks[i]];
11                long long allowed=val+space+1;
12                if(currentday<allowed){
13                    currentday=allowed;
14                }
15            }
16            mp[tasks[i]]=currentday;
17        }
18        return currentday;
19    }
20};