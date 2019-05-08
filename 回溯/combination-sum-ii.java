class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> res=new ArrayList<List<Integer>>();
        List<Integer> mid=new ArrayList<Integer>();
        cs2(candidates,0,target,mid,res);
        return res;
    }
    
    void cs2(int[] can,int idx,int target,List<Integer> mid,List<List<Integer>> res){
        if(target==0){
            res.add(new ArrayList<Integer>(mid));
            return;
        }
        if(target<0 || idx>=can.length){
            return;
        }
        
        int end=idx;
        while(end<can.length && can[end]==can[idx])end++;
        cs2(can,end,target,mid,res);
        for(int i=0;i<end-idx;i++){
            mid.add(can[idx]);
            cs2(can,end,target-can[idx]*(i+1),mid,res);
        }
        for(int i=0;i<end-idx;i++)
            mid.remove(mid.size()-1);
    }
}