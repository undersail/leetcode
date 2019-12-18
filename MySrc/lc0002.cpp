// https://leetcode-cn.com/problems/add-two-numbers/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 初等数学
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL || l2 == NULL) {
            return NULL;
        }
        ListNode* curNode1 = l1;
        ListNode* curNode2 = l2;
        int hVal = 0;
        int lVal = 0;
        while (curNode1 != NULL) {
            // l2比l1长的情况
            if (curNode1->next == NULL && curNode2 != NULL && curNode2->next != NULL) {
                curNode1->next = curNode2->next;
                curNode2->next = NULL;
            }
            int val = curNode1->val;
            if (curNode2 != NULL) {
                val += curNode2->val;
            }
            hVal = val / 10;
            lVal = val % 10;
            curNode1->val = lVal;
            // 进位的情况
            if (hVal > 0) {
                if (curNode1->next == NULL) {
                   curNode1->next = new ListNode(0); 
                }
                curNode1->next->val += hVal;                
            }
            curNode1 = curNode1->next;
            if (curNode2 != NULL) {
               curNode2 = curNode2->next; 
            }
        }
        return l1;
    }
};