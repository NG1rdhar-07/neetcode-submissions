/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carryVal = 0;
        ListNode *dmy = new ListNode(-1);
        ListNode *res = dmy;

        // while(l1 != nullptr && l2 != nullptr){  
        while(l1 != nullptr || l2 != nullptr || carryVal != 0){   // if anything is still left ....!!
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            int sum = val1 + val2 + carryVal;

            int nodeVal = sum % 10;
            // sum /= 10;
            carryVal = sum / 10;

            ListNode *newNode = new ListNode(nodeVal);
            res -> next = newNode;

            res = res -> next; //forgot

            if(l1 != nullptr)
            l1 = l1 -> next;

            if(l2 != nullptr)
            l2 = l2 -> next;
        }

        return dmy -> next;
    }
};
