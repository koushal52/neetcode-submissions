class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> v;
        int n=position.size();
        for(int i=0;i<n;i++){
            double time=(double)(target-position[i])/speed[i];
            v.push_back({position[i],time});
        }

        sort(v.begin(),v.end());
        double prevtime=0;
        int fleet=0;
        for(int i=n-1;i>=0;i--){
            double curr=v[i].second;

            if(curr>prevtime){
                fleet++;
                prevtime=curr;
            }
        }
        return fleet;
    }
};
