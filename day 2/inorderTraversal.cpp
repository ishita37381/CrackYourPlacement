class Solution {
public:
void solve(vector<int>&ans,TreeNode* root){
    if(!root)return;
    if(root->left)solve(ans,root->left);
    ans.push_back(root->val);
    if(root->right) solve(ans,root->right);
}
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        solve(ans,root);
        return ans;
    }
};
