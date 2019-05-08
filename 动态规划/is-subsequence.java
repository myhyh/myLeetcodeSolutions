class Solution {
    public boolean isSubsequence(String s, String t) {
        char[] a=s.toCharArray();
        char[] b=t.toCharArray();
        int i=0,j=0;
        for(;i<a.length && j<b.length;j++){
            if(a[i]==b[j])
                i++;
        }
        if(i==a.length)
            return true;
        return false;
    }
}