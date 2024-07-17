class Solution {
public:
TreeNode* create(vector<int>preorder,int preStart,int preEnd,vector<int>inorder
,int inStart,int inEnd,map<int,int>&mp){
    if(preStart>preEnd or inStart>inEnd)return NULL;
    TreeNode* root=new TreeNode(preorder[preStart]);
    int inRoot=mp[preorder[preStart]];
    int inLeft=inRoot-inStart;
    root->left=create(preorder,preStart+1,preStart+inLeft,inorder,inStart,inStart+inLeft,mp);
    root->right=create(preorder,preStart+inLeft+1,preEnd,inorder,inRoot+1,inEnd,mp);
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode* res=create(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return res;
    }
};
