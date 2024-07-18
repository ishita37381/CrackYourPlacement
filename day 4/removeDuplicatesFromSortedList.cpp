class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
        return head;
        ListNode* curr=head;
        while(curr){
            if((curr->next)&& curr->val==curr->next->val){
                ListNode* next_next=curr->next->next;
                ListNode* nodetodelete=curr->next;
                delete(nodetodelete);
                curr->next=next_next;

            }
            else{
                curr=curr->next;
            }
        }
        return head;

        
    }
};
