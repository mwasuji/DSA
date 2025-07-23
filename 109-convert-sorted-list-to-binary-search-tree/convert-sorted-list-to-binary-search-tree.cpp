/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

    int getlength(ListNode* head){
        ListNode* temp = head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp = temp->next;
        }return cnt;
    }
  
    TreeNode* solve(ListNode* &head , int n ){
        if (head == NULL || n<= 0){
            return NULL;
        }
          // LNR
          //L

          TreeNode* leftSubtree = solve(head , n/2);

          // N
          // ab head mid node pe khada honga 
          TreeNode * root = new TreeNode(head-> val);
          root->left = leftSubtree;

          //ab head mid pr khada tha , uska aage bhejo

          head = head->next;
          //ab head right part of ll k start par khada honga 
          TreeNode* rightSubtree = solve (head, n-n/2-1);
          root->right = rightSubtree;
          return root;


    }




    TreeNode* sortedListToBST(ListNode* head) {
       int n = getlength(head);
       TreeNode* root =solve(head, n);
       return root; 
    }
};