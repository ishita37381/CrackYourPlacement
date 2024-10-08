class Solution {
    ListNode* reverse(ListNode* & head){
        if(head==NULL || head->next==NULL)
        return head;
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* forw=NULL;
        while(curr!=NULL){
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
        return prev;
    }
    ListNode* get_mid(ListNode* head)
    {
        ListNode* slow = head;
        
        ListNode* fast = head -> next;
        
        // move slow by 1 step and fast by two step
        
        while(fast && fast -> next)
        {
            slow = slow -> next;
            
            fast = fast -> next -> next;
        }
        
        return slow;
    }
public:
    bool isPalindrome(ListNode* head) {
      ListNode* mid = get_mid(head);
        ListNode* list1 = head;
        ListNode* list2 = mid -> next;
      mid -> next = NULL;
        list2 = reverse(list2);
        while(list1 && list2)
        {
            if(list1 -> val != list2 -> val)
            {
                return false;
            }
            
            list1 = list1 -> next;
            
            list2 = list2 -> next;
        }
        
        return true;   
     }
};
