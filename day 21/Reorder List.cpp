class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> nodes;

        ListNode* dummy = head;

        while(dummy){
            nodes.push_back(dummy);
            dummy = dummy->next;
        }

        int l = 1, r = size(nodes)-1;

        for (int i = 0 ; i < size(nodes); ++i){
            if (i % 2 == 0){
                head->next = nodes[r--];
            }
            else{
                head->next = nodes[l++];
            }
            head = head->next;
        }

        head->next = nullptr;
    }
};
