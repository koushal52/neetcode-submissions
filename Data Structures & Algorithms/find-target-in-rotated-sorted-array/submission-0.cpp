class Solution {
public:
   int minele(vector<int>&nums){
    int start=0;
    int end=nums.size()-1;
    int n=nums.size();
    while(start<=end){
        if(nums[start]<=nums[end]) return start;
        int mid=start+(end-start)/2;
        int next=(mid+1)%n;
        int prev=(mid-1+n)%n;
        if(nums[next]>=nums[mid]&&nums[prev]>=nums[mid]){
            return mid;
        }
        else if(nums[start]<=nums[mid]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return -1;
   }

   int bs(vector<int>&nums,int start,int end,int target){
    while(start<=end){
        int mid=start+(end-start)/2;
        if(nums[mid]==target) return mid;
        if(nums[mid]<target){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return -1;
   }
    




    int search(vector<int>& nums, int target) {
        int mini=minele(nums);
        int left=bs(nums,0,mini-1,target);
        if(left!=-1) return left;
        return bs(nums,mini,nums.size()-1,target);
    }
};
