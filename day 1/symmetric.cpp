class Solution {
public:
bool solve(TreeNode* rleft,TreeNode* rright){
    if(rleft==NULL || rright==NULL)return rleft==rright;
    if(rleft->val!=rright->val)return false;
    return solve(rleft->left,rright->right)&& solve(rleft->right,rright->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        return solve(root->left,root->right);
    }
};
