class Solution 
{
    public:
    static bool cmp(Job &a,Job &b){
        return a.profit>b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        int count=0,profit=0;
        vector<int>temp(n+1,-1);
        sort(arr,arr+n,cmp);
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead;j>0;j--){
                if(temp[j]==-1){
                    temp[j]=arr[i].id;
                    profit+=arr[i].profit;
                    count++;
                    break;
                }
            }
        }
        return {count,profit};
    } 
};
