 Node  * merge(Node * l1,Node *l2){
        if(l2==NULL)return l1;
        Node * res=new Node(0);
        Node * curr=res;
        while(l1!=NULL | l2!=NULL){
            if(l2==NULL or(l1!=NULL and l1->data<l2->data)){
                curr->bottom=l1;
                l1=l1->bottom;
            }
            else {
                curr->bottom=l2;
                l2=l2->bottom;
            }
            curr=curr->bottom;
        }
        return res->bottom;
    }
Node *flatten(Node *head)
{
   if(head==NULL)return head;
   Node * l2=flatten(head->next);
   return merge(head,l2);
}
