class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        //int median=n%2==1?nums[n/2]:(nums[n/2]+nums[n/2+1])/2;
        int steps=0;
       int i=0,j=n-1;
       while(i<j){
        steps+=nums[j]-nums[i];
        i++;j--;
       }
        return steps;
    }
};
