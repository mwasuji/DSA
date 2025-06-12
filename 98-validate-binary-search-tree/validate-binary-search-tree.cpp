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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        bool isBST = true;
        TreeNode* cur = root;
        long prev = (long)INT_MIN-1;
        while(cur){
            if(cur->left == NULL){
                if(cur->val <= prev) isBST = false;
                prev = cur->val;
                cur = cur->right;
            }
            else{
                TreeNode* temp = cur->left;
                while(temp->right && temp->right != cur) temp = temp->right;
                if(temp->right == NULL){
                    temp->right = cur;
                    cur = cur->left;
                }
                else{
                    temp->right = NULL;
                    if(cur->val <= prev) isBST = false;
                    prev = cur->val;
                    cur = cur->right;
                }
            }
        }
        return isBST;
    }
};