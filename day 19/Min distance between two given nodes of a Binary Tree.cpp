class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node* lca(Node* root,int a,int b){
        if(root==NULL or root->data==a or root->data==b)return root;
        Node*left=lca(root->left,a,b);
        Node* right=lca(root->right,a,b);
        if(left!=NULL and right!=NULL)return root;
        if(left)return left;
        return right;
    }
    int solve(Node* root,int a){
        if(root==NULL)return 0;
        if(root->data==a)return 1;
        int l=solve(root->left,a);
        int r=solve(root->right,a);
        if(!l and !r)return 0;
        else return l+r+1;
        
    }
    int findDist(Node* root, int a, int b) {
        Node* f=lca(root,a,b);
        int d1=solve(f,a);
        int d2=solve(f,b);
        return d1+d2-2;
    }
};
