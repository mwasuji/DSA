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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if (root == NULL){
            return NULL;
        }

        // case 1 p and q and both on left side
        // right ko kiya neglect and left ko select kiya

        if (p->val < root-> val && q-> val < root-> val ){
            TreeNode* leftans = lowestCommonAncestor(root->left , p ,q);
            if (leftans != NULL){
                return leftans;
            }
        }

        // case2 p and q are both in  right side
        if (p->val > root-> val && q-> val > root-> val ){
            TreeNode*  rightans = lowestCommonAncestor(root->right , p ,q);
            if (rightans != NULL){
                return rightans;
            }
        }
          // case 3 p in left side and q in right side 
          // case 4 q in left side and q in left side
        return root;
    }
};