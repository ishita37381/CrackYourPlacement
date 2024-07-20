class BSTIterator {
    vector<int>v;
    int size=0,curr=0;
    void inorder(TreeNode* root){
        if(!root)return ;
        inorder(root->left);
        v.push_back(root->val);
        size++;
        inorder(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
     int next() {
        return v[curr++];
    }
    bool hasNext() {
        return curr<size;
    }
};
