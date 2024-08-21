void radixSort(int arr[], int n) 
{ 
   // code here
   int maxi =0;
   for(int i=0;i<n;i++) maxi = max(maxi,arr[i]);
   int iterations = log10(maxi)+1;
   
   int mod=10; 
   
    while(iterations--)
    {
        map<int, vector<int>> values;
        
        for(int i=0;i<n;i++)
        {   
             values[arr[i] % mod].push_back(arr[i]);
        }
        
        int i=0;
        for(auto x: values)
        {
            for(auto y: x.second){
                arr[i++] = y;
            }
        }
        mod *=10;
    }
} 
