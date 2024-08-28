class Solution {
public:
    int check(vector<vector<int>>& matrix, int mid) {
        int count = 0;
        int n = matrix.size();
        int row = 0;
        int col = n - 1;
        while (row < n && col >= 0) {
            if (matrix[row][col] <= mid) {
                count += (col + 1);
                row++;
            } else {
                col--;
            }
        }
        return count;
    }

    int kthSmallest(std::vector<std::vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(matrix, mid) < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};
