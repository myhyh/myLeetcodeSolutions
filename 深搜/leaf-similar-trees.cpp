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
    typedef list<TreeNode*>::iterator iter;
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        auto l1=leafs(root1);
        auto l2=leafs(root2);
        if(l1.size()!=l2.size())
            return false;
        for(iter a=l1.begin(),b=l2.begin();a!=l1.end() && b!=l2.end();a++,b++){
            if((*a)->val!=(*b)->val)
                return false;
        }
        return true;
    }
    list<TreeNode*> leafs(TreeNode* root){
        if(root==NULL)
            return {};
        if(root->left==NULL && root->right==NULL)
            return {root};
        auto l1=leafs(root->left);
        auto l2=leafs(root->right);
        l1.splice(l1.end(),l2);
        return l1;
    }
};