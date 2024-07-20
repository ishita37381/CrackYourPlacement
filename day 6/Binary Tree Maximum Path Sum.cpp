class Solution {
public:
int solve(TreeNode* root,int& ans){
    if(root==NULL)return 0;
    int left=solve(root->left,ans);
    int right=solve(root->right,ans);
    int temp=max(max(left,right)+root->val,root->val);
    int res=max(temp,left+right+root->val);
    ans=max(ans,res);
    return temp;
}
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        solve(root,ans);
        return ans;
    }
};
