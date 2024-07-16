class Solution {
public:
#define ll long long
    int widthOfBinaryTree(TreeNode* root) {
        int max_width=INT_MIN;
        queue<pair<TreeNode*,int>>q;// node and index
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            int min_idx=q.front().second;
            int first,last;
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front().first;
                int curridx=q.front().second;
                curridx-=min_idx;
                q.pop();
                if(i==0)first=curridx;
                if(i==n-1)last=curridx;
                if(curr->left)q.push({curr->left,(ll)2*curridx+1});
                if(curr->right)q.push({curr->right,(ll)2*curridx+2});
            }
            max_width=max(max_width,last-first+1);
        }
        return max_width;


    }
};
