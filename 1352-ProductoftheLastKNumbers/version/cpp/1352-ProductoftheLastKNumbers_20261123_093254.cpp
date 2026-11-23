// Last updated: 11/23/2026, 9:32:54 AM
1class ProductOfNumbers {
2public:
3    vector<int> arr;
4    ProductOfNumbers() {
5        arr.resize(0);
6    }
7    
8    void add(int num) {
9        arr.push_back(num);
10    }
11    
12    int getProduct(int k) {
13        int prod=1;
14        int n=arr.size();
15        int i=n-1;
16        while(k){
17            prod*=arr[i];
18            i--;
19            k--;
20        }
21        return prod;
22    }
23};
24
25/**
26 * Your ProductOfNumbers object will be instantiated and called as such:
27 * ProductOfNumbers* obj = new ProductOfNumbers();
28 * obj->add(num);
29 * int param_2 = obj->getProduct(k);
30 */