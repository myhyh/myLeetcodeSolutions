class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) {
            return 0;
        }

        int depthMax = 0;
        for (int idx = 0; idx < root->children.size(); ++idx) {
            int depth = maxDepth(root->children[idx]);
            if (depth > depthMax) {
                depthMax = depth;
            }
        }
        return depthMax + 1;
    }
};