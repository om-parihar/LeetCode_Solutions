// Last updated: 7/25/2026, 10:58:41 PM
class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> p;
    int k;
    KthLargest(int k, vector<int>& nums) {
        int n=nums.size();
        this->k=k;
        for(int i=0;i<n;i++){
            p.push(nums[i]);
            if(p.size()>k){
                p.pop();
            }
        }
    }
    
    int add(int val) {
        p.push(val);
        if(p.size()>k){
            p.pop();
        }
        return p.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */