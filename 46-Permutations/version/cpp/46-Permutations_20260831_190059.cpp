// Last updated: 8/31/2026, 7:00:59 PM
1class Solution {
2public:
3    void perm(vector<int> &nums, vector<int> &temp, vector<bool> &avail,int &cnt){
4        if(temp.size()==nums.size()){
5            cnt++;
6        }
7        else{
8            int pos=temp.size()+1;
9            for(int j=0;j<nums.size();j++){
10                if(avail[j]){
11                    int num=nums[j];
12                    if(num%pos==0 || pos%num==0){
13                        temp.push_back(num);
14                        avail[j]=false;
15                        perm(nums,temp,avail,cnt);
16                        avail[j]=true;
17                        temp.pop_back();
18                    }
19                }
20            }
21        }
22    }
23    int countArrangement(int n) {
24        vector<bool> avail(n,1);
25        vector<int> temp;
26        vector<int> nums(n,0);
27        for(int i=1;i<=n;i++){
28            nums[i-1]=i;
29        }
30        int cnt=0;
31        perm(nums,temp,avail,cnt);
32        return cnt;
33    }
34};