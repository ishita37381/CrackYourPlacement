class Solution{
public:
Node * solve(Node * ptr){
    Node * even=new Node(-1);
    Node * odd=new Node(-1);
    Node *tempE=even,*tempO=odd;
    while(ptr){
        if(ptr->data&1){
            tempO->next=new Node(ptr->data);
            tempO=tempO->next;
        }else {
            tempE->next=new Node(ptr->data);
            tempE=tempE->next;
        }
        ptr=ptr->next;
    }
    tempE->next=odd->next;
    return even->next;
}
    Node* divide(int N, Node *head){
       head=solve(head);
       return head;
    }
};
