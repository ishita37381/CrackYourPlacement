class Solution{
    public:
    int sameChar(string A, string B)
    {
        int count=0;
        for(int i=0;i<A.size();i++){
            if(tolower(A[i])==tolower(B[i]))count++;
        }
        return count;
    }
};
