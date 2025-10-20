class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode smallDummy(0), largeDummy(0);
        ListNode *small = &smallDummy, *large = &largeDummy;
        while(head){
            if(head->val < x){
                small->next = head;
                small = small->next;
            } 
            else {
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }
        large->next = nullptr;
        small->next = largeDummy.next;
        return smallDummy.next;
    }
};