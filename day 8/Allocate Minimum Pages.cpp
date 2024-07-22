class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool ispossible(int A[], int N, int M,int mid){
        int count=1;
        int pagesum=0;
        for(int i=0;i<N;i++){
       if(A[i]>mid)
       return false;
       if(pagesum+A[i]>mid){
           count++;
           pagesum=A[i];
           if(count>M)
           return false;
       }
       else{
           pagesum+=A[i];
       }
        }
       return true;
    }
    int findPages(int A[], int N, int M) 
    {
       int s=0;
       int sum=0;
       for(int i=0;i<N;i++){
           sum+=A[i];
       }
       int e=sum;
       int  mid=s+(e-s)/2;
       int res=-1;
       if(N<M) return -1;
       while(s<=e){
           if(ispossible(A,N,M,mid)){
               res=mid;
               e=mid-1;
           }
           else{
               s=mid+1;
           }
           mid=s+(e-s)/2;
       }
       return res;
    }
};
