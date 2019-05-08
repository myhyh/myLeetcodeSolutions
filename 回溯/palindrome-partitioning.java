class Solution {
    //可以进一步优化,把st,ed,对应的返回值放在一个boolean[][]里,那么只用求一次即可
    boolean isPal(String s,int st,int ed){
        while(ed>st){
            if(s.charAt(st)!=s.charAt(ed-1))
                return false;
            st++;
            ed--;
        }
        return true;
    }
    public List<List<String>> partition(String s) {
        List<List<String>> res=new ArrayList<List<String>>();
        List<String> mid=new ArrayList<String>();
        part(s,0,mid,res);
        return res;
    }
    void part(String s,int st,List<String> mid,List<List<String>> res){
        int ed=s.length();
        if(st==ed){
            res.add(new ArrayList<String>(mid));
            return;
        }
        for(int i=st+1;i<=ed;i++){
            if(isPal(s,st,i)){
                mid.add(s.substring(st,i));
                part(s,i,mid,res);
                mid.remove(mid.size()-1);
            }
        }
    }
}