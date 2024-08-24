class Solution {
public:
    vector<int>arr;
    int n;
    int dp[20000+1][2];
    int maxPointsEarned(int idx,int flag){
        int ans = 0;
        if(idx == n){
            return 0;
        }
        if(dp[idx][flag] != -1){
            return dp[idx][flag];
        }
        if(flag == 0 || idx == 0){
            int i = idx;
            int sum = 0;
            while(i < n and arr[i] == arr[idx]){
                sum += arr[i];
                i++;
            }
            ans = maxPointsEarned(i,1) + sum;
            ans = max(ans,maxPointsEarned(idx+1,0));
        }
        else{
            if(arr[idx] - arr[idx-1] == 1){
                int i = idx;
                while(i < n and arr[i] == arr[idx]){
                    i++;
                }
                ans = max(ans,maxPointsEarned(i,0));
            }else{
            int i = idx;
            int sum = 0;
            while(i < n and arr[i] == arr[idx]){
                sum += arr[i];
                i++;
            }
            ans = maxPointsEarned(i,1) + sum;
            ans = max(ans,maxPointsEarned(idx+1,0));
            }
        }
        return dp[idx][flag] = ans;
    }

    int deleteAndEarn(vector<int>& nums) {
        arr = nums;
        sort(arr.begin(),arr.end());
        n = arr.size();
        memset(dp,-1,sizeof(dp));
        int x = maxPointsEarned(0,0);
        return x;
    }
};
