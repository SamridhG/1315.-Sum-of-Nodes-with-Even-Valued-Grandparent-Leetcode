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
    int sam;
    Solution(){
        sam=0;
    }
    void sumE(TreeNode *root)
    {
        if(root->left!=NULL)
        {
            if(root->left->left!=NULL)
            {
                sam+=root->left->left->val;
            }
            if(root->left->right!=NULL)
            {
                sam+=root->left->right->val;
            }
        }
        if(root->right!=NULL)
        {
            if(root->right->left!=NULL)
            {
                sam+=root->right->left->val;
            }
            if(root->right->right!=NULL)
            {
                sam+=root->right->right->val;
            }
        }
    }
    void inorder(TreeNode *root)
    {
      if(root!=NULL)
      {
          inorder(root->left);
          if(root->val%2==0)
          {
              sumE(root);
          }
          inorder(root->right);
      }
    }
    int sumEvenGrandparent(TreeNode* root) {
        inorder(root);
        return sam;
    }
};
