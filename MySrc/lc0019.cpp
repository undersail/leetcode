// https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 链表操作
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> nodes;
        while (head != NULL) {
            nodes.push_back(head);
            head = head->next;
        }
        if (n < 1 || n > nodes.size()) {
            return NULL;
        }
        int index = nodes.size() - n;
        if (index == 0) {
            return nodes[0]->next;
        } else if (index == nodes.size() - 1) {
            nodes[index - 1]->next = NULL;
        } else {
            nodes[index - 1]->next=nodes[index]->next;
        }
        return nodes[0];
    }
};