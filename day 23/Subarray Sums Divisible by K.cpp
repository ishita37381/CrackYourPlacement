class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
      unordered_map<int,int>mp;
     int sum=0,res=0;
     for(int i=0;i<nums.size();i++){
        if(nums[i]>=0)sum+=nums[i];
        else sum+=k+(nums[i]%k);
        mp[sum%k]++;
        if(sum%k!=0)res+=mp[sum%k]-1;
        else res+=mp[sum%k];
        sum=sum%k;
     }

     return res;
    }
};
