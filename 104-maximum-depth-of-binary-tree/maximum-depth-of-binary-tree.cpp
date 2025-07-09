/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
       if (root == NULL){
        return 0;
       }

       int leftsubtreeheight= maxDepth(root->left);
       int rightsubtreeheight= maxDepth(root->right);
       int maxheight = max(leftsubtreeheight,rightsubtreeheight)+1;
       return maxheight;



    }
};