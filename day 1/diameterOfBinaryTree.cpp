class Solution {
public:
int height(int&ans,TreeNode* root){
    if(!root)return 0;
    int left=height(ans,root->left);
    int right=height(ans,root->right);
    ans=max(ans,left+right);
    return max(left,right)+1;
}
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        int ans=0;
        height(ans,root);
        return ans;
    }
};
