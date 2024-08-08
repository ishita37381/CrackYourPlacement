class Solution {
public:
 ListNode* findMid(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast != NULL && fast->next !=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
  }
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        tail->next = list1 ? list1 : list2;
        return dummy.next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next == NULL){
            return head;
        }
        ListNode* mid = findMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;
        left = sortList(left);
        right = sortList(right);

        ListNode*  merged = merge(left,right);
     return merged;
    }
};
