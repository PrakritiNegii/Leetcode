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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;

        queue<pair<TreeNode*,int>> q;
        q.push({root,0});  

        ans.push_back({});
        ans[0].push_back(root->val);

        while(!q.empty())
         {
          TreeNode* node = q.front().first;
          int level = q.front().second;
          q.pop();

          cout<<node->val<<"\t"<<level<<endl;

          TreeNode* l = node->left;
          TreeNode* r = node->right;

          if((l || r) && ans.size()<=level+1) ans.push_back({});
          
          if(l!=NULL)
             {
               q.push({l,level+1});
               ans[level+1].push_back(l->val);
             }
          if(r!=NULL)
             {
               q.push({r,level+1});
               ans[level+1].push_back(r->val);
             }
         }

        for(int i=0; i<ans.size(); i++)
         {
          if(i%2==1) reverse(ans[i].begin(),ans[i].end());
         }
       return ans;
    }
};