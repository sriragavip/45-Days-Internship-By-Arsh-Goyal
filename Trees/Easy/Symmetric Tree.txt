class Solution {
private:
    bool isEquivalent(TreeNode* left, TreeNode* right) {
        if (!left || !right) return left == right;
        else return left->val == right->val && isEquivalent(left->left, right->right) && isEquivalent(right->left, left->right);
    }

public:
    bool isSymmetric(TreeNode* root) {
        return isEquivalent(root->left, root->right);
    }
};