// https://leetcode-cn.com/problems/binary-tree-postorder-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 二叉对，后序遍历：左->右->根
// 递归，题目描述：递归算法很简单，你可以通过迭代算法完成吗？
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        // 递归
        LastTraversal(root, res);
        return res;
    }
    
private:
    void LastTraversal(TreeNode* curNode, vector<int>& res)
    {
        if (curNode->left != NULL) {
            LastTraversal(curNode->left, res);
        }
        if (curNode->right != NULL) {
            LastTraversal(curNode->right, res);
        }
        res.push_back(curNode->val);
    }
};
