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
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return balanced;
    }

    int dfs(TreeNode* node)
        {
            if(node == nullptr)
                return 0;
            
            int left = dfs(node->left);
            int right = dfs(node->right);

            if(abs(left-right) > 1)
                balanced = false;

            return 1 + max(left, right);

        }
        bool balanced = true;
};