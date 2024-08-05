class Solution {
public:
void solve(int index,vector<int>&v,vector<int>&nums,vector<vector<int>>&ans,int n){
    ans.push_back(v);
    for(int i=index;i<n;i++){
        if(i>index and nums[i]==nums[i-1])continue;
        v.push_back(nums[i]);
        solve(i+1,v,nums,ans,n);
        v.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>v;
        sort(nums.begin(),nums.end());
        solve(0,v, nums,ans,n);
        return ans;
    }
};
