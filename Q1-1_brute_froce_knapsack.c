
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define max(a,b) (a>b?a:b)

int bruteforce(int W, int wt[], int val[], int n);
int matrix[100][100];

int main(int argc, char *argv[])
{
    char line1[128]; int A[100];
    int tempW=0; int bestV=0, bestW=0;
    int tempV=0;
    char line2[128];
    char line3[128];
    char line4[128]; 
    char *pt;
    int max1;
    int i=0;
    int tot_wt;
    int a;
    int v[10];  
    int w[10];  
    char const* const fileName = argv[1]; 
    FILE* f = fopen(fileName, "r"); 
    if (!f) 
    {
        printf("ERROR");
    } 
    else 
    {
        fscanf(f, "%127[^\n]\n%127[^\n]\n%127[^\n]\n%127[^\n] ", line1, line2,line3, line4);
        
        max1=atoi(line1);       
        printf("NUMBER OF OBJECTS:%d\n",max1);  //line1

        
        do 
        {
            pt = strtok (line2,",");
            while (pt != NULL) 
            {
                w[i] = atoi(pt);        
                //printf("%d\n", w[i]);
                i++;
                pt = strtok (NULL, ",");
            }
        }while(i<max1);
    
        
        i=0;
        
        do 
        {
            pt = strtok (line3,",");
            while (pt != NULL) 
            {
                v[i] = atoi(pt);        
                i++;
                pt = strtok (NULL, ",");
            }
        }while(i<max1);
    
        printf("WEIGHT:");
        for(i=0;i<max1;i++)
        printf("%d\n", w[i]);

        printf("PROFIT:");
        for(i=0;i<max1;i++)
        printf("%d\n", v[i]);
        
        tot_wt=atoi(line4);
        printf("CAPACITY:%d",tot_wt);
        

       //printf("\nmaximum value: %d"
        bruteforce(max1,tot_wt,w,v);

        fclose(f);
    }
    

    return 0;
}

int bruteforce(int W, int wt[], int val[], int n){
  int i, w, g=0;
    int Wt1[n+1][W+1]; int x; int value[n];
    
    for (i = 0; i <= n; i++)
    {   //for (g = 0;g<n;g++)
        for (w = 0; w <= W; w++)
        {
            if (i==0 || w==0)
            {           
                Wt1[i][w] = 0; value[i]=0;
            }           
            else if (wt[i-1] <= w)
            {
                // Wt1[i][w] = max(val[i-1] +Wt1[i-1][w-wt[i-1]],  Wt1[i-1][w]); 
                if((val[i-1] +Wt1[i-1][w-wt[i-1]])>(Wt1[i-1][w]))
                {
                    Wt1[i][w] =val[i-1] +Wt1[i-1][w-wt[i-1]];
                    value[i]=val[i];
                }
                }
                else
                { 
                    Wt1[i][w] = Wt1[i-1][w]; value[i]=val[i];
                
                } 

            
        }
    }
    printf("\nMAXIMUM PROFIT ACHIEVED:%d\n",Wt1[n][W]); //printf("\nselected values:\t%d",Wt1[n][W]);
    printf("VALUES USED:\n");
    for (g = 0; g< n; g++) if(value[g]!=0) printf("%d\n", value[g]); 

}