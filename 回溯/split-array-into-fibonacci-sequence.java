class Solution {
    public List<Integer> splitIntoFibonacci(String S) {	//暴力求解...
        final int n=S.length();
        List<Integer> res=new ArrayList<Integer>();
        for(int i=1;i<n && i<10;i++){
            if (S.charAt(0) == '0' && i > 1) break;
            for(int j=i+1;j<n && j<i+10;j++){
                if (S.charAt(i) == '0' && j > i+1) break;
                res.clear();
                int num1=Integer.parseInt(S.substring(0,i));
                int num2=Integer.parseInt(S.substring(i,j));
                int k=j;
                while(true){
                    int num3=num1+num2;
                    String num3s=String.valueOf(num3);
                    int l3=num3s.length();
                    if(l3+k<=n && num3s.equals(S.substring(k,k+l3))){
                        res.add(num1);
                        if(k+l3==n){
                            res.add(num2);
                            res.add(num3);
                            return res;
                        }
                        num1=num2;
                        num2=num3;
                        k+=l3;
                    }else{
                        break;
                    }
                }
            }
        }
        return new ArrayList<Integer>();
    }
}