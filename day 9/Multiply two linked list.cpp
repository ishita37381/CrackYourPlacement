long long  multiplyTwoLists (Node* l1, Node* l2)
{
  Node * h1=l1;
  Node * h2=l2;
  long long num1=0,num2=0;
  long long mod=1000000007;
  while(h1){
      num1=(num1*10+h1->data)%mod;
      h1=h1->next;
  }
  while(h2){
      num2=(num2*10+h2->data)%mod;
      h2=h2->next;
  }
  return (num1*num2)%mod;
}
