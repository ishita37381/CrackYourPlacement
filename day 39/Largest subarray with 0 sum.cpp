class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        // Your code here
        unordered_map<int,int> m;
        m[0]=0;
        int prefixSum = 0;
        int i=0;
        int size = 0;
        while(i<n)
        {
            prefixSum+=arr[i];
            if(m.count(prefixSum))
            {
                int j = m[prefixSum];
                size = max(size,i-j+1);
            }
            else{
                m[prefixSum]=i+1;
            }
            i++;
        }
        return size;
    }
};
