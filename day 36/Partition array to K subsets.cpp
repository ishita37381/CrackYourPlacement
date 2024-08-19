class Solution{
  public:
    void findSubsets(int a[], int n, set<vector<int>> &subsets){
        for(int i=1; i<pow(2,n); i++){
            vector<int> vec(n,0);
            int j=i;
            int k=(n-1);
            while(j>0){
               if(j%2==1){
                  vec[k]=1; 
               } 
               k--;
               j=j>>1;
            }
            vector<int> temp;
            for(int p=0; p<n; p++){
                if(vec[p]==1){
                    temp.push_back(a[p]);
                }
            }
            subsets.insert(temp);
            temp.clear();
            vec.clear();
        }    
    }
    bool isKPartitionPossible(int a[], int n, int k)
    {
         
         if(k==1){
             return true;
         }
         if(n<k){
             return false;
         }
         int total=0;
         for(int i=0; i<n; i++){
             total+=a[i];
         }
         if(total%k!=0){
             return false;
         }
         int res=total/k;
         set<vector<int>> subsets;
         vector<bool> visited(101, false);
         findSubsets(a,n,subsets);
         int count=0;
         for(auto vec: subsets){
             vector<int> temp = vec;
             int sum=0;
             
             for(int i=0; i<temp.size(); i++){
                 sum+=temp[i];
                 if(!visited[temp[i]] && temp[i]<=res){
                    
                     visited[temp[i]]=true;
                 }
             }
             if(sum==res){
                 count++;
             }
         }
         int c=0;
         for(int i=0; i<n; i++){
             if(visited[a[i]]){
                 c+=1;
             }
         }
       return count>=k && c==n;
    }
};
