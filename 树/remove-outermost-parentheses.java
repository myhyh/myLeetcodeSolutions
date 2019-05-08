class Solution {
    public String removeOuterParentheses(String S) {
        int cnt=0;
        StringBuilder b=new StringBuilder();
        for(char c:S.toCharArray()){
            
            if(c=='('){
                if(cnt!=0)
                    b.append(c);
                cnt++;
            }else{
                cnt--;
                if(cnt!=0)
                    b.append(c);
            }
        }
        return b.toString();
    }
}