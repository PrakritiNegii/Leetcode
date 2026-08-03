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
    vector<vector<int>> levelOrder(TreeNode* root) {
       if(root==nullptr) return {};
       
       vector<vector<int>> res;

       queue<TreeNode*> q;
       q.push(root);

       while(!q.empty())
        {
         vector<int> level;
         int loop = q.size();
         while(loop!=0)
          {
           TreeNode* node = q.front();
           q.pop();
           int val = node->val;
           level.push_back(node->val);

           if(node->left != NULL)
                q.push(node->left);
           if(node->right != nullptr)
                q.push(node->right);

           loop--;
          }
         res.push_back(level);
        }

       return res;
    }
};