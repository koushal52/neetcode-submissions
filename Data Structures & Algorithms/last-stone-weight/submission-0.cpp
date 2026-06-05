class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max_h;
        for(int x:stones){
            max_h.push(x);
        }
        while(max_h.size()>1){
            int x=max_h.top();
            max_h.pop();
            int y=max_h.top();
            max_h.pop();
            if(x!=y){
                max_h.push(x-y);
            }
        }
        if(max_h.empty()) return 0;
        return max_h.top();
    }
};
