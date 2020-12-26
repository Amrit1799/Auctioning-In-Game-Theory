#include<stdio.h>
#include<math.h>

void swap(double* a, double* b)         // function to swap two variables
{  
    double t = *a;  
    *a = *b;  
    *b = t;  
}

int partition (double arr[], int low, int high)    // partitioning in quick sort
{  
    int pivot = arr[high]; 
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)  
    {  
        if (arr[j] < pivot)  
        {  
            i++;   
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  

int sort(double arr[],int low,int high)         // quick-sort function
{
    if (low < high)  
    {  
        int pi = partition(arr, low, high);  
  
        sort(arr, low, pi - 1);  
        sort(arr, pi + 1, high);  
    }  
}

void main(){
    
    printf("        Welcome to Second Price Auction      \n");
    
    int NoP;  // number of bidders.
    double valarr[10],bidarr[10];
    double m;   //expected payment
    printf("Enter the number of Bidders");
    scanf("%d",&NoP);
    
    printf("Enter the Valuation of each bidder:\n");
    for(int i=0;i<NoP;i++)
    {
        scanf("%lf",&valarr[i]);
    }
    
    sort(valarr, 0, NoP-1);
    
    double bidFun = ((double)NoP - 1) / (double)NoP;  // calculation of the bid to pay.
    
    printf("Second Price Auction bid will be:\n");
    for(int i =0; i<NoP; i++){
        bidarr[i] = 1 * valarr[i];
        printf("For valuation %g bid amount will be:\t%g\n",valarr[i],bidarr[i]);
    }
    
    m = pow(valarr[NoP-1], NoP);        
    m = bidFun * m;                     
    
    printf("Expected Revenue:%0.01g\n",m);
}

 
