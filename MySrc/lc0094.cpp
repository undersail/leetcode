// https://leetcode-cn.com/problems/binary-tree-inorder-traversal/

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        
        // 递归
        MidTraversal(root, res); 
        
        // 迭代
        /*
        TreeNode* curNode = root;
        stack<TreeNode*> nodeHistory;
        while (curNode != NULL) {
            nodeHistory.push(curNode);
            if (curNode->left != NULL) {
                curNode = curNode->left;
                continue;
            }
            res.push_back(curNode->val);
            if (curNode->right != NULL) {
                curNode = curNode->right;
                continue;
            }
            nodeHistory.pop();
            curNode = nodeHistory.top();
        }
        */
        return res;
    }

private:
    void MidTraversal(TreeNode* curNode, vector<int>& res)
    {
        if (curNode->left != NULL) {
            MidTraversal(curNode->left, res);
        }
        res.push_back(curNode->val);
        if (curNode->right != NULL) {
            MidTraversal(curNode->right, res);
        }
    }
};