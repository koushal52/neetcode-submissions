class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> freq=new HashMap<>();
        int n=nums.length;
        for(int i=0;i<n;i++){
            int required=target-nums[i];
            if(freq.containsKey(required)){
                return new int[]{freq.get(required),i};
            }
            freq.put(nums[i],i);
        }
        return new int[]{};
    }
}
