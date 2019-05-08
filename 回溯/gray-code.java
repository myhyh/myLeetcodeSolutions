class Solution {
    //找规律,长度为n的graycode就是长度为n-1的graycode倒着补上去并把最高位置1,实质考数字电路...
    public List<Integer> grayCode(int n) {
        List<Integer> res=new ArrayList<Integer>();
        res.add(0);
        for(int i=0;i<n;i++){
            int cur=1<<i;
            int l=res.size();
            for(int j=l-1;j>=0;j--){
                res.add(res.get(j)+cur);
            }
        }
        return res;
    }
}