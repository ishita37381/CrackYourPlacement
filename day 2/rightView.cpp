class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
       vector<int>ans;
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        ans.push_back(root->val);
        ans.clear();
        while(!q.empty()){
            int n=q.size();
            for(int i=1;i<=n;i++){
                TreeNode* temp=q.front();
            if(i==n)ans.push_back(temp->val);
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
            q.pop();
            }
        }
        return ans;
    }
};
