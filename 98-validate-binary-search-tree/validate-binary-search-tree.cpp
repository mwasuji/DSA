class Solution {
public:
    bool isbst(TreeNode* root, long min, long max) {
        if (root == NULL) return true;

        if (root->val > min && root->val < max) {
            return isbst(root->left, min, root->val) &&
                   isbst(root->right, root->val, max);
        } else {
            return false;
        }
    }

    bool isValidBST(TreeNode* root) {
        return isbst(root, LONG_MIN, LONG_MAX);
    }
};
