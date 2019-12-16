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
class Solution {
public:
    int rob(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        if(cache.find(root) != cache.end()) {
            return cache[root];
        }
        int maxValue1 = rob(root->left) + rob(root->right);
        int maxValue2 = root->val;
        if (root->left != NULL && root->right != NULL) {
            maxValue2 += rob(root->left->left) + rob(root->left->right) + rob(root->right->left) + rob(root->right->right);
        } else if (root->left != NULL) {
            maxValue2 += rob(root->left->left) + rob(root->left->right);
        } else if (root->right != NULL) {
            maxValue2 += rob(root->right->left) + rob(root->right->right);
        }
        cache[root] = max(maxValue1, maxValue2);
        return max(maxValue1, maxValue2);
    }
private:
    map<TreeNode*,int> cache;
};