class Solution {
    private:
    typedef pair<int,pair<int,int>> ppi;
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<ppi> max_h;
        int n=points.size();
        vector<vector<int>> ele;
        for(int i=0;i<n;i++){
            int x=points[i][0];
            int y=points[i][1];
            int dist=x*x+y*y;
            max_h.push({{dist},{x,y}});
            if(max_h.size()>k){
                max_h.pop();
            }
        }
        while(!max_h.empty()){
            ele.push_back({max_h.top().second.first,max_h.top().second.second});
            max_h.pop();
        }
        return ele;

    }
};
