class Solution {
public:
int solve(int left,int right,vector<int>&nums,vector<vector<int>>&dp){
    if(left>right)return 0;
    if(dp[left][right]!=-1)return dp[left][right];
    int res=0;
    for(int k=left;k<=right;k++){
        int coins=nums[left-1]*nums[k]*nums[right+1];
        int remaining=solve(left,k-1,nums,dp)+solve(k+1,right,nums,dp);
        res=max(res,coins+remaining);
    }
    dp[left][right]=res;
    return res;

}
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        return solve(1,n,nums,dp);
    }
};
