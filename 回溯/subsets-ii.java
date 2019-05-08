class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res=new ArrayList<List<Integer>>();
        swd(nums,0,new ArrayList<Integer>(),res);
        return res;
    }
    
    public void swd(int[] nums,int start,List<Integer> mid,List<List<Integer>> res){
        if(start==nums.length){
            res.add(new ArrayList<>(mid));
            return;
        }
        int end=start;
        while(end<nums.length&&nums[end]==nums[start])
            end++;
        for(int i=0;i<=end-start;i++){
            swd(nums,end,mid,res);
            mid.add(nums[start]);           
        }
        for(int i=0;i<=end-start;i++){
            mid.remove(mid.size()-1);
        }
    }
}