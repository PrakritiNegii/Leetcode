/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) 
 {    
  if(root==NULL)
    return NULL;
  if(!(root->left) && !(root->right))
    return root;
  root->left = invertTree(root->left);
  root->right = invertTree(root->right);
  struct TreeNode *temp = root->left;
  root->left = root->right;
  root->right = temp;
  return root;
 }