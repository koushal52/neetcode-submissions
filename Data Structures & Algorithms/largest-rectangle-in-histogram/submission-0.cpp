
class Solution {
public:
    vector<int> nearestleft(vector<int>&heights){
        vector<int> left;
        stack<pair<int,int>> st;
        int pseudo=-1;
        for(int i=0;i<=heights.size()-1;i++){
           if(st.size()==0){
            left.push_back(pseudo);
           }
           else if(st.size()>0&&st.top().first<heights[i]){
            left.push_back(st.top().second);
           }
           else if(st.size()>0&&st.top().first>=heights[i]){
            while(st.size()>0&&st.top().first>=heights[i]){
                st.pop();
            }
            if(st.size()==0){
                left.push_back(pseudo);
            }
            else{
                left.push_back(st.top().second);
            }
           }
           st.push({heights[i],i});
        }
        return left;
    }




     vector<int> nearestright(vector<int>&heights){
        vector<int> right;
        stack<pair<int,int>> st;
        int pseudo=heights.size();
        for(int i=heights.size()-1;i>=0;i--){
           if(st.size()==0){
            right.push_back(pseudo);
           }
           else if(st.size()>0&&st.top().first<heights[i]){
            right.push_back(st.top().second);
           }
           else if(st.size()>0&&st.top().first>=heights[i]){
            while(st.size()>0&&st.top().first>=heights[i]){
                st.pop();
            }
            if(st.size()==0){
                right.push_back(pseudo);
            }
            else{
                right.push_back(st.top().second);
            }
           }
           st.push({heights[i],i});
        }
        reverse(right.begin(),right.end());
        return right;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> left=nearestleft(heights);
        vector<int> right=nearestright(heights);
        vector<int> width(n);
        for(int i=0;i<n;i++){
            width[i]=(right[i]-left[i]-1);
        }

        vector<int> area(n);
        for(int i=0;i<n;i++){
            area[i]=heights[i]*width[i];
        }
        int maxi=*max_element(area.begin(),area.end());
        return maxi;
    }
};