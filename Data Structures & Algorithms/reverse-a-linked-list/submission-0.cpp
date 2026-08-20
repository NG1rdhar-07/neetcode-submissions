class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr)
        return head;

        ListNode *prev = nullptr;
        ListNode *temp = head;
        ListNode *front = temp -> next;

        while(front != nullptr){
            front = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }
};