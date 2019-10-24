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