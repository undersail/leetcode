// https://leetcode-cn.com/problems/symmetric-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 二叉树，递归
class Solution {
private:
    bool IsMirror(TreeNode* node1, TreeNode* node2)
    {
        // 处理特殊情况
        if (node1 == NULL && node2 == NULL) {
            return true;
        } if ((node1 == NULL && node2 != NULL) || (node1 != NULL && node2 == NULL)) {
            return false;
        } else {
            // 关键点：val相等且左-左与右-右对称、左-右与右-左对称
            return (IsMirror(node1->left, node2->right) && IsMirror(node1->right, node2->left) && node1->val == node2->val);
        }
    }

public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        } else {
            return IsMirror(root->left, root->right);
        }
    }
};
