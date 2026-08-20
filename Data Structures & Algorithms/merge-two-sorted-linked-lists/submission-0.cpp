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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *h1 = list1;
        ListNode *h2 = list2;

        if(h1 == nullptr)
        return h2;

        if(h2 == nullptr)
        return h1;

        // ListNode *fnl = nullptr;
        ListNode *dmy = new ListNode();
        ListNode *fnl = dmy;

        while(h1 != nullptr && h2 != nullptr){
            // if(h1 -> val == h2 -> val){
            //     fnl -> next = new ListNode(h1 -> val);
            //     fnl -> next = new ListNode(h2 -> val);
            //     h1 = h1 -> next;
            //     h2 = h2 -> next;
            // }

            if(h1 -> val >= h2 -> val)
            {
                fnl -> next = new ListNode(h2 -> val);
                fnl = fnl -> next;
                h2 = h2 -> next;
            }

            else{
                fnl -> next = new ListNode(h1 -> val);
                fnl = fnl -> next;
                h1 = h1 -> next;
            }
        }

        if(h1 != nullptr)
        {
            fnl -> next = h1;
        }

        if(h2 != nullptr)
        {
            fnl -> next = h2;
        }

        return dmy -> next;
    }
};
