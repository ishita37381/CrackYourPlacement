class Solution {
    int length( ListNode* head){
        if(head==NULL)
        return 0;
        
            int cnt=0;
         while(head!=NULL){
             head=head->next;
             cnt++;
         }
         return cnt;

    
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)
        return head;
     int len=  length(head); 
     if(n==len)
     return head->next;
     if(n>len)
     return head;
     int k=len-n+1;
      ListNode* temp=head;
      
       int cnt=1;
       while( temp!=NULL && cnt<k-1){
          
           temp=temp->next;
           cnt++;
       }
     temp->next=temp->next->next;
          return head;
    }
};
