class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
      vector<long long int>v;
      if(n==1){
          v.push_back(1);
          return v;
      }
      for(int i=0;i<n;i++){
          int index=i;
          long long  int prod=1;
          for(int j=0;j<n;j++){
              if(j!=index)
              prod*=nums[j];
          }
         v.push_back(prod);
      }
      return v;
    }
};
