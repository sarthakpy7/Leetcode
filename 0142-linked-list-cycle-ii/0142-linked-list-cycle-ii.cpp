class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
    if(head == NULL || head->next == NULL) return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        bool check=true;


        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                check=false;
                break;
            }

        }

    if(check){
        return NULL;
    }else{
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;

        }
        return slow;
    }
        
    }
};