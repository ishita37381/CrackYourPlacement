class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head or left==right)return head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        int pos=1;
        ListNode* nodeBeforeSublist=dummy;
        while(pos<left){
            nodeBeforeSublist=nodeBeforeSublist->next;
            pos++;
        }
        ListNode* workingPtr=nodeBeforeSublist->next;
        while(left<right){
            ListNode* nodeToBeExtracted=workingPtr->next;
            workingPtr->next=nodeToBeExtracted->next;
            nodeToBeExtracted->next=nodeBeforeSublist->next;
            nodeBeforeSublist->next=nodeToBeExtracted;
            left++;
        }
        return dummy->next;
    }
};
