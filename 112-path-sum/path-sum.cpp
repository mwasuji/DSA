class Solution {
public:
    bool solve(TreeNode* root, int sum, int target) {
        if (root == NULL) {
            return false;
        }

        sum = sum + root->val;

        // If it's a leaf node
        if (root->left == NULL && root->right == NULL) {
            return sum == target;
        }

        bool leftans = solve(root->left, sum, target);
        bool rightans = solve(root->right, sum, target);

        return leftans || rightans;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return solve(root, sum, targetSum);
    }
};
