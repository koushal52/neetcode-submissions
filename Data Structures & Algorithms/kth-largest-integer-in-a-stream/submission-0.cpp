class KthLargest {
    private:
    priority_queue<int,vector<int>,greater<int>> min_h;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int x:nums){
            min_h.push(x);
            if(min_h.size()>k){
                min_h.pop();
            }
        }
    }
    
    int add(int val) {
        min_h.push(val);
        if(min_h.size()>k){
            min_h.pop();
        }
        return min_h.top();
    }
};
