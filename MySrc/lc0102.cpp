// https://leetcode-cn.com/problems/binary-tree-level-order-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 二叉树，层序遍历
class Solution {

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        int index = 0;
        // 递归，index表示层序号
        traverse(result, root, index);
        return result;
    }

private:
    void traverse(vector<vector<int>>& result, TreeNode* node, int& index)
    {
        if (node == NULL) {
            return;
        }
        if (result.size() <= index) {
            vector<int> nodeVal;
            nodeVal.push_back(node->val);
            result.push_back(nodeVal);
        } else {
            result[index].push_back(node->val);
        }
        // 关键点：子节点层序号+1
        int index1 = index + 1;
        int index2 = index + 1;
        traverse(result, node->left, index1);
        traverse(result, node->right, index2);
    }
};
