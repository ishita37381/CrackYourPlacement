class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)return false;
        if(!root->left and ! root->right){
            return targetSum==root->val;
        }
        bool lsum=hasPathSum(root->left,targetSum-root->val);
        bool rsum=hasPathSum(root->right,targetSum-root->val);
        return lsum or rsum;
    }
};
