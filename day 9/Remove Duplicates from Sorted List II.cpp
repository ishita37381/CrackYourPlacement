class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
      ListNode* dummy=new ListNode(0);
      dummy->next=head;
      ListNode* prev=dummy;
      ListNode* temp=head;
      while(temp!=NULL and temp->next!=NULL){
        if(temp->val==temp->next->val){
            int data=temp->val;
            while(temp!=nullptr and temp->val==data){
                ListNode* del=temp;
                temp=temp->next;
                delete del;
            }
            prev->next=temp;
            
            }
            else{
                prev=temp;
                temp=temp->next;
            }
      }
      head=dummy->next;
      delete dummy;
      return head;
    }
};
