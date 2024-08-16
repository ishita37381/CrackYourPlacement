class Solution {
public:
    long long binomialCoefficient(int n, int k) {
        long long res = 1;
        
        if (k > n - k) {
            k = n - k;
        }
       
        for (int i = 0; i < k; ++i) {
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }

    int numTrees(int n) {
        long long c = binomialCoefficient(2 * n, n);
        return c / (n + 1);
    }
};
