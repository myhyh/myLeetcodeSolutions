class Solution {
    static List<String> mapl=Arrays.asList("","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz");
    public List<String> letterCombinations(String digits) {
        List<String> res=new ArrayList();
        if("".equals(digits)){
            return res;
        }
        StringBuilder sb=new StringBuilder();
        LC(digits,0,sb,res);
        return res;
    }
    void LC(String digits,int idx,StringBuilder mid,List<String> res){
        if(idx==digits.length()){
            res.add(mid.toString());
            return;
        }
        for(char c:mapl.get(digits.charAt(idx)-'0').toCharArray()){
            mid.append(c);
            LC(digits,idx+1,mid,res);
            mid.deleteCharAt(mid.length()-1);
        }
    }
}