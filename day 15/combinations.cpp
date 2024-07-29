class Solution {
public:
void backtrack(int start,vector<int>&comb,vector<vector<int>>&ans,int n,int k){
    if(comb.size()==k){
        ans.push_back(comb);
        return;
    }
    for(int i=start;i<=n;i++){
        comb.push_back(i);
        backtrack(i+1,comb,ans,n,k);
        comb.pop_back();
    }
}
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>comb;
        backtrack(1,comb,ans,n,k);
        return ans;
    }
};
