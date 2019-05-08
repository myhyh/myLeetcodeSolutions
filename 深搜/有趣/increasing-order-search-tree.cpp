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
    TreeNode* cur;
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode fake=TreeNode(0);
        cur=&fake;
        inorder(root);
        return fake.right;
    }
    
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        root->left=NULL;
        cur->right=root;
        cur=root;
        inorder(root->right);
    }
};