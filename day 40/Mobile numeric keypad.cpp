  long long getCount(int n) {
       long long sum = 0;
       if(n==1)
       {
           return 10;
       }
       vector<long long>prev(10,1);
       vector<long long>next(10,1);
       for(int i=2;i<n;i++)
       {
           next[0] = prev[0] + prev[8];
           next[1] = prev[1] + prev[2] + prev[4];
           next[2] = prev[2] + prev[1] + prev[3] + prev[5];
           next[3] = prev[3] + prev[2] + prev[6];
           next[4] = prev[4] + prev[1] + prev[7] + prev[5];
           next[5] = prev[5] + prev[2] + prev[4] + prev[6] + prev[8];
           next[6] = prev[6] + prev[3] + prev[5] + prev[9];
           next[7] = prev[7] + prev[4] + prev[8];
           next[8] = prev[8] + prev[0] + prev[7] + prev[9] + prev[5];
           next[9] = prev[9] + prev[6] + prev[8];
           for(int j=0;j<10;j++)
           {
               prev[j] = next[j];
           }
       }
       for(int i=0;i<10;i++)
       {
           if(i==0)
           {
               sum+=(prev[i]*2);
           }
           else if(i==1 || i==3 || i==7 || i== 9)
           {
               sum+=(prev[i]*3);
           }
           else if(i==2 || i ==4 || i==6)
           {
               sum+=(prev[i]*4);
           }
           else
           {
               sum+=(prev[i]*5);
           }
       }
       return sum;
    }
