// https://leetcode-cn.com/problems/house-robber-iii/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 递归+状态记录，map用法
class Solution {
public:
    int rob(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        if(cache.find(root) != cache.end()) {
            return cache[root];
        }
        // 每个子循环分为两种情况
        // 一：不抢当前根节点，则金额=抢左子树金额+抢右子树金额
        int maxValue1 = rob(root->left) + rob(root->right);
        // 二：抢当前根节点，则金额=根金额+下一层的全部金额
        int maxValue2 = root->val;
        if (root->left != NULL && root->right != NULL) {
            maxValue2 += rob(root->left->left) + rob(root->left->right) + rob(root->right->left) + rob(root->right->right);
        } else if (root->left != NULL) {
            maxValue2 += rob(root->left->left) + rob(root->left->right);
        } else if (root->right != NULL) {
            maxValue2 += rob(root->right->left) + rob(root->right->right);
        }
        // 当前根节点对应的金额放入缓存
        cache[root] = max(maxValue1, maxValue2);
        return max(maxValue1, maxValue2);
    }
private:
    // cache 中保存每一根节点对应的最高金额
    map<TreeNode*,int> cache;
};
