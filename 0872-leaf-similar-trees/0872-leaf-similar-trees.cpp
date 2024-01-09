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
bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> nodeArr1;
        vector<int> nodeArr2;
        inorder(root1, nodeArr1);
        inorder(root2, nodeArr2);
        return nodeArr1 == nodeArr2;
    }
    bool inorder(TreeNode *tree, vector<int> &arr)
    {
        // return 0 if current is leaf
        bool is_leaf = true;
        if (!tree)
        {
            return 0;
        }
        if (tree->left)
        {
            inorder(tree->left, arr);
        }
        if (tree->right)
        {
            inorder(tree->right, arr);
        }
        if (!tree->left && !tree->right)
        {
            arr.push_back(tree->val);
        }
        return 0;
    }
};