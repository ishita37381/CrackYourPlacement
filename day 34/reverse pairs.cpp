class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int count=0;

        auto mergeSort = [&](auto&& self, int l, int r)->void{
            if(l == r)return;
            int m = (l+r)/2;
            self(self, l, m);
            self(self, m+1, r);

            vector<int> temp(r-l+1);
            int j = m+1;
            int first = m+1;
            for(int i=l, k = 0;i<=m;++i,++k)
            {
                while(first <= r && nums[i]/2.0> nums[first])first++;
                while(j<=r && nums[j]<nums[i])temp[k++]=nums[j++];
                count+=first-m-1;
                temp[k] = nums[i];
            }
            for(int i=0;i<j-l;i++)nums[i+l]=temp[i];
        };
        mergeSort(mergeSort, 0, nums.size()-1);
        return count;
    }
};
