class Solution {
public:
    int getheight(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int leftheight = getheight(root->left);
        int rightheight = getheight(root->right);
        int maxheight = max(leftheight, rightheight) + 1;
        return maxheight;
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) { // ✅ fixed '=' to '=='
            return true;
        }

        // first case solve karra hu
        int lh = getheight(root->left);
        int rh = getheight(root->right);
        int absdiff = abs(lh - rh);
        int status = (absdiff <= 1);

        // recursion
        int leftans = isBalanced(root->left);
        int rightans = isBalanced(root->right);

        if (status && rightans && leftans) {
            return true;
        } else {
            return false; // ✅ fixed missing return
        }
    }
};
