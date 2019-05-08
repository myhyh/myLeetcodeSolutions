/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root==NULL)
            return 0;
        int res=0;
        bool isL = ( root->val >= L);
        bool isR = ( root->val <= R);
        if(isR){
            res+=rangeSumBST(root->right,L,R);
        }
        if(isL){
            res+=rangeSumBST(root->left,L,R);
        }
        if(isR && isL)
            res+=root->val;
        return res;
    }
};