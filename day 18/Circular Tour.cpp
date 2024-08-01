class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       int deficient=0;
       int balance=0;
       int start=0;
       for(int i=0;i<n;i++){
           balance+=p[i].petrol-p[i].distance;
           if(balance<0){
               deficient+=balance;
               balance=0;
               start=i+1;
           }
       }
       if(balance+deficient>=0)return start;
       else return -1;
    }
};
