class Solution {
public:
ListNode* reverse(ListNode* head){
    ListNode*prev,*next,*curr;
    curr=head;
    prev=NULL;
    next=nullptr;
    while(curr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p=reverse(l1);
        ListNode* q=reverse(l2);
        ListNode *head, *last;
        head=last=new ListNode(-1);
        
        int carry=0;
        while(p!=NULL || q!=NULL){
            int d=(p!=NULL ? p->val:0) + (q!=NULL ? q->val:0) + carry;
            
            ListNode *temp=new ListNode(d%10);
            last->next=temp;
            last=temp;
            
            carry=d/10;
            
            if(p) p=p->next;
            if(q) q=q->next;
        }
        
        if(carry!=0){
            ListNode *temp=new ListNode(carry);
            last->next=temp;
            last=temp;
        }
        
        head=head->next;
        head=reverse(head);
        
        return head;

    }
};
