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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();
        unordered_set<int> child;
        unordered_map<int,vector<pair<int,int>>> parent;

        for(int i=0; i<n; i++)
         {
          int p = descriptions[i][0];
          int c = descriptions[i][1];
          int l = descriptions[i][2];

          child.insert(c);
          parent[p].push_back({c,l});
         }

        int root;
        for(int i=0; i<n; i++)
         {
          int p = descriptions[i][0];
          
          if(child.count(p)==0) //if the parent found is not anyones child then the parent found is the root node
           {
            root = p;
            break;
           }
         }

        TreeNode *rt =  new TreeNode();;
        rt->val = root;
        rt->left = NULL;
        rt->right = NULL;

        queue<TreeNode*> q;
        q.push(rt);

        while(!q.empty())
         {
          TreeNode *node = q.front();
          q.pop();

          auto arr = parent[node->val];
          for(int i=0; i<arr.size(); i++)
           {
            int v = arr[i].first;
            int l = arr[i].second;
            TreeNode *t =  new TreeNode();
            t->val = v;
            t->left = NULL;
            t->right = NULL;

            q.push(t);

            if(l==1) 
              node->left = t;
            else 
              node->right = t;
           }
         }

       return rt;
    }
};