bool check(Node* root,int min,int max){
    if(!root)return false;
    if(min==max)return true;
    return check(root->left,min,root->data-1)or check(root->right,root->data+1,max);
}
bool isDeadEnd(Node *root)
{
    
    return check(root,1,INT_MAX);
}
