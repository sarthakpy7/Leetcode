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
    bool sufficient_nodes(ListNode* temp,int k){
        while(k && temp){
            temp = temp->next;
            k--;
        }
        return temp==NULL? false:  true;
    };

    ListNode* reverseKGroup(ListNode* head, int k) {
        // create the dummy node which will be pointed by the first pointer
        ListNode *first = new ListNode(-1);
        first -> next = head;
        head = first;
        // our iteration will run until last node
        ListNode *prev,*curr,*front,*second;
        while(first->next!=NULL){
            int x = k;
            second = first->next;
            prev = first;
            curr = first->next;
            // check if k nodes are there(passing k-1 as for k nodes k-1 edges will be there)
            if(!sufficient_nodes(second,k-1)){
                break;
            }
            // run until we reverse k nodes
            while(x!=0 && curr!=NULL){
                front = curr->next;
                curr->next = prev;
                prev = curr;
                curr=front;
                x--;
            }
            // set the linkage between first , second for next group of k nodes
            first->next = prev;
            second->next = curr;
            first = second; // important for new first pointer node
            
        }
        // After all reverse done delete the dummy node and return actual head
        first = head;
        head = head-> next;
        delete first;
        return head;
    }
};