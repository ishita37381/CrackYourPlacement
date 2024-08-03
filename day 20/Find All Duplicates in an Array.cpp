class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
      vector<int>ans;
      sort(nums.begin(),nums.end());
      int n=nums.size();
      for(int i=0;i<n-1;i++){
        if(nums[i]==nums[i+1]){
            ans.push_back(nums[i]);
        }
      }
        return ans;
    }
};
