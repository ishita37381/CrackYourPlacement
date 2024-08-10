class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        queue<pair<TreeNode *,pair<int,int>>> q; 
        map<int, map<int,vector<int>>> mp;

        int level = 0;
        q.push({root,{0,level}});
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                auto top = q.front();
                q.pop();
                TreeNode *node = top.first;
                int line = top.second.first;

                // mp[line].push_back(node->val);
                mp[line][level].push_back(node->val);

                if(node->left)
                    q.push({node->left,{line-1,level}});
                if(node->right)
                    q.push({node->right,{line+1,level}});
            }
            level++;
        }
        for (auto it : mp) {
            vector<int> temp;
            for (auto x : it.second) {
                sort(x.second.begin(), x.second.end());
                for (int i : x.second) temp.push_back(i);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
