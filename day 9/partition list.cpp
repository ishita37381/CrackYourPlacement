class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small=new ListNode(0);
        ListNode* large=new ListNode(0);
        ListNode* smallHead=small;
        ListNode* largeHead=large;
        while(head!=NULL){
            if(head->val<x){
                smallHead->next=head;
                smallHead=smallHead->next;
            }
            else{
                largeHead->next=head;
                largeHead=largeHead->next;
            }
            head=head->next;
        }
        largeHead->next=NULL;
        smallHead->next=large->next;
        return small->next;
    }
};
