class Solution {
public:
void buildParent(TreeNode* root,unordered_map<TreeNode *, TreeNode *> &parent){
   if(root==NULL)return;
   if(root->left){
    parent[root->left]=root;
   }
   if(root->right){
    parent[root->right]=root;
   }
   buildParent(root->left,parent);
   buildParent(root->right,parent);
}
void find(TreeNode *node, int k, unordered_map<TreeNode *, TreeNode *> &parent,
 vector<int> &result, unordered_map<TreeNode *, bool> &visited){
if(node==NULL or k<0 or visited[node])return;
visited[node]=true;
if(k==0){
    result.push_back(node->val);
    return;
}
find(node->left, k-1, parent, result, visited);
find(node->right, k-1, parent, result, visited);
find(parent[node], k-1, parent, result, visited);

 }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        buildParent(root,parent);
        vector<int>res;
        unordered_map<TreeNode* ,bool>visited;
        find(target,k,parent,res,visited);
        return res;

    }
};
