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

   void storeinorder(TreeNode* root, vector<int>& inorder){
    if (root == NULL){
        return ;
    }
    //lnr

    storeinorder(root->left, inorder);
    inorder.push_back(root->val);
    storeinorder(root->right, inorder);

   }

   bool checktwosum(vector<int> arr,int target){
      int s =0;
      int n = arr.size();
      int e = n-1;

      while(s<e){
        int sum = arr[s]+ arr[e];
        if (sum== target){
            return true;
        }
        if (sum>target){
            e--;
        }if(sum<target){
            s++;
        }
      }
      return false; 
   }

    bool findTarget(TreeNode* root, int target) {
    vector<int> inorder;
    storeinorder(root , inorder);
    bool ans = checktwosum(inorder,target);    
    return ans;

    }
};