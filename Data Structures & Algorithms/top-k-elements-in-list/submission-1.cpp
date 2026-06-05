class Solution {
    typedef pair<int,int> ppi;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }

        priority_queue<ppi,vector<ppi>,greater<ppi>> heap;
        for(auto it:mp){
            heap.push({it.second,it.first});
            if(heap.size()>k){
                heap.pop();
            }
        }
        vector<int> result;
        while(!heap.empty()) {

            result.push_back(heap.top().second);

            heap.pop();
        }
       
        return result;
    }
};
