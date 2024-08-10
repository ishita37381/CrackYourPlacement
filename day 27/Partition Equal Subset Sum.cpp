// User function Template for C++

class Solution{
public:
bool subsetSumUtil(int ind, int target, int arr[], vector<vector<int>>& dp) {
    if (target == 0)
        return true;
    if (ind == 0)
        return arr[0] == target;
    if (dp[ind][target] != -1)
        return dp[ind][target];
    bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);
    bool taken = false;
    if (arr[ind] <= target)
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);
          return dp[ind][target] = notTaken || taken;
}
    int equalPartition(int N, int arr[])
    {
        int total=0;
        for(int i=0;i<N;i++)total+=arr[i];
        if(total%2==1)return 0;
        else{
            int k=total/2;
            vector<vector<int>>dp(N,vector<int>(k+1,-1));
            return subsetSumUtil(N-1,k,arr,dp);
        }
    }
};
