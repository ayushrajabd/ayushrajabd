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
    vector<int> nodes;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        nodes.push_back(root->val);
        inorder(root->right);
    }

    TreeNode* build(int start, int end) {
        if (start > end) return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nodes[mid]);
        root->left = build(start, mid - 1);
        root->right = build(mid + 1, end);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return build(0, nodes.size() - 1);
    }
};