class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        stack<TreeNode*>st;
        TreeNode* curr=root;
        while(curr or !st.empty()){
            while(curr){
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top();
            st.pop();
           cnt++;
            if(cnt==k)return curr->val;
            curr=curr->right;
        }
        return -1;
    }
};
