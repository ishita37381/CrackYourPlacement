class Solution {
public:
int length(ListNode* head){
    int len=0;
    while(head){
        len++;
        head=head->next;
    }
    return len;
}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=length(headA);
        int lenB=length(headB);
        while(lenA>lenB){
            lenA--;
            headA=headA->next;
        }
        while(lenB>lenA){
            lenB--;
            headB=headB->next;
        }
        while(headA and headB){
            if(headA==headB)return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
};
