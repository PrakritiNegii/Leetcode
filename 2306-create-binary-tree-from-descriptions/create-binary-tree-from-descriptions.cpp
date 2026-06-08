class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();
        TreeNode* root;
        unordered_map<int, TreeNode*> mp;

        for (int i = 0; i < n; i++) {
            int curr = descriptions[i][1];
            mp[curr] = new TreeNode(curr);
        }

        for (int i = 0; i < n; i++) {
            int parent = descriptions[i][0];
            int curr = descriptions[i][1];
            bool isLeft = descriptions[i][2];

            // find root
            if (mp.find(parent) == mp.end()) {
                mp[parent] = new TreeNode(parent);
                root = mp[parent];
            }

            TreeNode* parentNode = mp[parent];
            if (isLeft) {
                parentNode->left = mp[curr];
            } else {
                parentNode->right = mp[curr];
            }

            mp[parent] = parentNode;
        }

        return root;
    }
};