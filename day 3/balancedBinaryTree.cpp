class Solution {
public:
int height(TreeNode* root){
    if(!root)return 0;
    int left=height(root->left);
    int right=height(root->right);
    return max(left,right)+1;
}
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        int l=height(root->left);
        int r=height(root->right);
        if(abs(l-r)>1)return false;
        bool lf=isBalanced(root->left);
        bool rf=isBalanced(root->right);
        if(!lf or !rf)return false;
        return true;
    }
};
