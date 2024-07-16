class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr and q==NULL)return true;
        if(p and q and p->val==q->val){
            return isSameTree(p->left,q->left) and isSameTree(p->right,q->right);
        }
        return false;
    }
};
