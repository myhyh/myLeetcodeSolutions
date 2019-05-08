/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> res=new ArrayList<String>();
        if(root==null)
            return res;
        if(root.left==null&&root.right==null){
            res.add(String.valueOf(root.val));
            return res;
        }
        List<String> l=binaryTreePaths(root.left);
        List<String> r=binaryTreePaths(root.right);
        
        for(String s:l){
            res.add(String.valueOf(root.val)+"->"+s);
        }
        for(String s:r){
            res.add(String.valueOf(root.val)+"->"+s);
        }
        return res;
    }
}