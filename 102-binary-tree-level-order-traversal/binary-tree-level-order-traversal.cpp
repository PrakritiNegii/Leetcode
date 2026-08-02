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
        if(root==NULL) return {};

        queue<pair<TreeNode*,int>> q;
        q.push({root,0});

        vector<vector<int>> res;
        res.push_back({});

        while(!q.empty())
         {
          TreeNode *n = q.front().first;
          int level = q.front().second;
          q.pop();

          res[level].push_back(n->val);

          if(n->left != NULL)
           {
            q.push({n->left,level+1});
            if(res.size()<=level+1) res.push_back({});
           }
          if(n->right != NULL)
           {
            q.push({n->right,level+1});
            if(res.size()<=level+1) res.push_back({});
           }
         }

        return res;
    }
};