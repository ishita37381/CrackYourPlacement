class Solution {
  public:
    void rearrangeEvenOdd(Node *head) {
         if(head == nullptr || head->next == nullptr) return ;
        Node* even = new Node(-1);
        Node* odd = new Node(-1);
        Node* first = odd;
        Node* second = even;
        int i=1;
        Node* prevo = nullptr;
        Node* preve = nullptr;
        while(head){
            if(i % 2 != 0){
                odd->next = head;
                prevo = odd;
                odd = head;
            }
            else{
                even->next = head;
                preve = even;
                even = head;
            }
            head = head->next;
            i++;
        }
        if(!odd){
            prevo->next = second->next;
        }
        else{
            odd->next = second->next;
            even->next = nullptr;
        }
        head = first->next;
    }
};
