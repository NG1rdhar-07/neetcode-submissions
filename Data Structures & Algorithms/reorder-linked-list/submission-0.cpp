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
    void reorderList(ListNode* head) {
        ListNode *sp = head;
        ListNode *fp = head;

        while(fp != nullptr && fp -> next != nullptr){
            sp = sp -> next;
            fp = fp -> next -> next;
        }

        // ListNode *temp = head;

        // while(temp -> next != sp)
        // {
        //     temp = temp -> next;
        // }

        // temp -> next = nullptr;

        ListNode *scnd = sp -> next;
        sp -> next = nullptr;

        ListNode *prev = nullptr;
        ListNode *fN;// = new ListNode();

        while(scnd != nullptr){
            fN = scnd -> next;
            scnd -> next = prev;
            prev = scnd;
            scnd = fN;
        }

        ListNode *firstPtr = head;
        ListNode *secondPtr = prev;

        while(secondPtr != nullptr){
            ListNode *t1 = firstPtr -> next;
            ListNode *t2 = secondPtr -> next;

            firstPtr -> next = secondPtr;
            secondPtr -> next = t1;

            firstPtr = t1;
            secondPtr = t2;
        }
    }
};
