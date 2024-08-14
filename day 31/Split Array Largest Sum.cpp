class Solution {
public:
    bool solve(vector<int>& nums, int mid, int n, int k) {
        int sc = 1;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            if (sum + nums[i] > mid) {
                sc++;
                sum = nums[i];
                if (sc > k || nums[i] > mid)
                    return false;
            } else {
                sum += nums[i];
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        int ans = -1, s = 0, e = sum;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (solve(nums, mid, n, k)) {
                ans = mid;
                e = mid - 1;
            } else
                s = mid + 1;
        }
        return ans;
    }
};
