class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> min_h;
        for(int x:nums){
            min_h.push(x);
            if(min_h.size()>k){
                min_h.pop();
            }
        }
        return min_h.top();
    }
};
