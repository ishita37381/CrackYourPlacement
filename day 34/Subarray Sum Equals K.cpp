class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      int currSum = 0;
      int ans = 0;
      unordered_map<int, int> prefix;
      prefix[0] = 1;

       for(int i = 0; i < nums.size(); i++){
         currSum += nums[i];
         int prefixSum = currSum - k;

         if(prefix.find(prefixSum) != prefix.end()){
            ans += prefix[prefixSum];
         }
         

         if(prefix.find(currSum) == prefix.end()){
            prefix[currSum] = 1;
         }
         else prefix[currSum] = 1 + prefix[currSum];

       }  
       return ans;
    }
};
