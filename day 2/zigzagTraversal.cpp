class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root)return res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>ans;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                q.pop();
                ans.push_back(temp->val);
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
           res.push_back(ans);
        }
        for(int i=0;i<res.size();i++){
            if(i%2==1)reverse(res[i].begin(),res[i].end());
        }
        return res;
    }
};
