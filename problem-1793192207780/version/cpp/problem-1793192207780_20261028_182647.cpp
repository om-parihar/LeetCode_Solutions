// Last updated: 10/28/2026, 6:26:47 PM
1class StockSpanner {
2public:
3    vector<int> arr;
4    stack<pair<int,int>> st;
5    int idx=0;
6    StockSpanner() {
7        arr.clear();
8    }
9    
10    int next(int price) {
11    while (!st.empty() && st.top().first <= price) {
12        st.pop();
13    }
14
15    int ans = st.empty() ? idx + 1 : idx - st.top().second;
16
17    st.push({price, idx});
18    idx++;
19
20    return ans;
21    }
22};
23
24// class StockSpanner1 {
25// public:
26//     vector<int> arr;
27//     StockSpanner() {
28//         arr.clear();
29//     }
30    
31//     int next(int price) {
32//         arr.push_back(price);
33//         int cnt=1;
34//         for(int i=arr.size()-2;i>=0;i--){
35//             if(arr[i]<=price){
36//                 cnt++;
37//             }
38//             else{
39//                 break;
40//             }
41//         }
42//         return cnt;
43//     }
44// };
45
46/**
47 * Your StockSpanner object will be instantiated and called as such:
48 * StockSpanner* obj = new StockSpanner();
49 * int param_1 = obj->next(price);
50 */