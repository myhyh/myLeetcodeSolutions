/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        stack<tuple<Node*,int,int>> stk;
        if(root==NULL)
            return 0;
        stk.push({root,0,root->children.size()});
        Node* cn;int ci,cs;
        int maxD=1;
        while(!stk.empty()){
            tie(cn,ci,cs)=stk.top();
            if(ci==cs){
                stk.pop();
                continue;
            }
            int oci=get<1>(stk.top())++;
            Node* newnode=cn->children[oci];
            stk.push({newnode,0,newnode->children.size()});
            maxD=max(maxD,(int)stk.size());
        }
        return maxD;
    }
};