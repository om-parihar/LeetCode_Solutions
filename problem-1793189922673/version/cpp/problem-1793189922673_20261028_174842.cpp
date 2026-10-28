// Last updated: 10/28/2026, 5:48:42 PM
1class StockSpanner {
2public:
3    vector<int> arr;
4    StockSpanner() {
5        arr;
6    }
7    
8    int next(int price) {
9        arr.push_back(price);
10        int cnt=1;
11        for(int i=arr.size()-2;i>=0;i--){
12            if(arr[i]<=price){
13                cnt++;
14            }
15            else{
16                break;
17            }
18        }
19        return cnt;
20    }
21};
22
23/**
24 * Your StockSpanner object will be instantiated and called as such:
25 * StockSpanner* obj = new StockSpanner();
26 * int param_1 = obj->next(price);
27 */