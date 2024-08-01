class Solution {
public:
int solve(TreeNode* root,bool isLeft){
    if(!root)return 0;
    if(!root->left and !root->right){
        return isLeft?root->val:0;
    }
    int leftsum=solve(root->left,true);
    int rightsum=solve(root->right,false);
    return leftsum+rightsum;
}
    int sumOfLeftLeaves(TreeNode* root) {
       return solve(root,false);
    }
};
