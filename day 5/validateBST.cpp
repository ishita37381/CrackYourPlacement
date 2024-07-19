class Solution {
public:
vector<int>nodes;
void inorder(TreeNode* root){
    if(root->left)inorder(root->left);
    nodes.push_back(root->val);
    if(root->right)inorder(root->right);
}
    bool isValidBST(TreeNode* root) {
        inorder(root);
        for(int i=0;i<nodes.size()-1;i++){
            if(nodes[i]>=nodes[i+1])return false;
        }
        return true;
        
    }
};
