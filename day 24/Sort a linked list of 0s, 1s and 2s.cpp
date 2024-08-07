class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
       int zero=0,one=0,two=0;
       Node * temp =head;
       while(temp){
           if(temp->data==0)zero++;
           else if ( temp->data==1)one++;
           else two++;
           temp=temp->next;
       }
       temp=head;
       while(temp){
           if(zero>0){
               temp->data=0;
               zero--;
           }
           else if (one>0){
               temp->data=1;
               one--;
           }
           else if (two>0){
               temp->data=2;
               two--;
           }
           temp=temp->next;
       }
        return head;
    }
};
