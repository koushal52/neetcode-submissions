class Solution {
    public int[] getConcatenation(int[] nums) {
        int n=nums.length;
        int[] list=new int[2*n];
        for(int i=0;i<n;i++){
            list[i]=nums[i];
            list[i+n]=nums[i];
        }
        return list;
    }
}