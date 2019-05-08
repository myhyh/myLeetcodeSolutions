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
    public int rangeSumBST(TreeNode root, int L, int R) {
        if(root==null)
            return 0;
        boolean l=root.val>=L;
        boolean r=root.val<=R;
        int result=0;
        if(l){
            result+=rangeSumBST(root.left,L,R);
        }
        if(r){
            result+=rangeSumBST(root.right,L,R);
        }
        if(l&&r){
            result+=root.val;
        }
        return result;
    }
}