#include<stdio.h>

int max(int a, int b) { 
if(a>b)
{
	return a;
}
else
{
	return b;
}

}
char convert(int i)
{
    return (i%26) + 'A';
}
void combinationUtil(int harf[],int arr[],int arr1[],int n,int r,int index,int data[],int i, int data1[],int nesne[]);


void knapSack(int W, int wt[], int val[], int n,int harf[]) {
   int i, w;
   int K[n + 1][W + 1];
 
   for (i = 0; i <= n; i++) {
      for (w = 0; w <= W; w++) {
         if (i == 0 || w == 0)
            K[i][w] = 0;
         else if (wt[i - 1] <= w)
            K[i][w] = max(val[i - 1] +
            K[i - 1][w - wt[i - 1]], K[i - 1][w]);
         else
            K[i][w] = K[i - 1][w];
      }
   }
 
   int maxValue = K[n][W];
   int sumWeights=0;
   int sumValue=0;
   printf("\n\n    En Uygun Cozumu Sunan Dugum\n\n ");
 
 
 	 printf("Nesneler\tAgirliklar\tDegerler\n");
   w = W;
   for (i = n; i > 0 && maxValue > 0; i--) {
      if (maxValue == K[i-1][w])
         continue;
      else {
        
            printf("%c\t\t%d\t\t%d\n",convert(harf[i-1]),wt[i-1],val[i-1]);
           maxValue = maxValue - val[i - 1];
         w = w - wt[i - 1];
         sumWeights+=wt[i-1];
         sumValue+=val[i-1];
         
      }
   }
   printf("\nBu nesnelerin agirliklari toplami = %d\n",sumWeights);
   printf("\nBu nesnelerin degerlerinin toplami = %d\n",sumValue);
   
}



void printCombination(int harf[],int arr[],int arr1[], int n, int r)
{
    int nesne[r];
    int data[r];
    int data1[r];
    
 	combinationUtil(harf,arr,arr1, n, r, 0, data, 0, data1,nesne);
 
    
}
 

void combinationUtil(int harf[],int arr[],int arr1[], int n, int r, int index, int data[], int i,int data1[],int nesne[])
{
    int sumW=0;
    int sumV=0;
    int j;
   
  
    if (index == r)
    {	
	
		printf("Nesneler\tAgirliklar\tDegerler\n");
        for (j=0; j<r; j++)
        {
        	 
        	  printf("%c\t\t%d\t\t%d\n",convert(nesne[j]),data[j],data1[j]);
        	 	
        	 sumW+=data[j];
            sumV+=data1[j];
		}
		
		
		
			printf("\nAgirliklar Toplami= %d\nDegerler Toplami= %d\n",sumW,sumV);
			printf("_________________________________________\n\n");
			
	
			
		
        
        
      
        return;
    }
 
   
    if (i >= n)
        return;
 

    data1[index] = arr1[i];
       data[index] = arr[i];
       nesne[index]=harf[i];
   
    combinationUtil(harf,arr,arr1, n, r, index+1, data, i+1,data1,nesne);
 

    combinationUtil(harf,arr,arr1, n, r, index, data, i+1,data1,nesne);
}


int main()
{
    int i, n, v[5], w[5], c;

    n=5;
    int harf[5]={0,1,2,3,4};
	char nesneler [5]={'A','B','C','D','E'};
    printf("Cantanin kapasitesini giriniz:");
    scanf("%d", &c);
     if(c<5 || 25<c )
        {
        	printf("!!! Girilen kapasite nesne sayisina bagli olarak 5-25 arasinda olmalidir !!!");
        	return 0;
		}
   
    printf("\nNesnelerin degerlerini ve agirliklarini giriniz:\n\n");
   for (i = 0; i < n; ++i) {
   	
   	
   	 printf("%c nin agirligi: ",nesneler [i]);
        scanf("%d", &w[i]);
        if(w[i]<1 || w[i]>c)
        {
        	printf("!!! Girilen agirlik 1 den kucuk veya kapasiteden buyuk alamaz !!!");
        	return 0;
		}
        printf("%c nin degeri: ",nesneler [i]);
        scanf("%d", &v[i]);
        if(v[i]<1 || v[i]>n*n)
        {
        	printf("!!! Girilen deger 1 den kucuk veya nesne sayisindan buyuk olamaz !!!");
        	return 0;
		}
            
       
        printf("\n");
    }
  				
				printf("K canta kapasitesine gore olasi cozumler:\n\n");
				printf("_________________________________________\n\n");
             	for(i=1;i<=5;i++)
             	{
             	
             		printCombination(harf,w,v, 5, i);
             	
				 }
                 
              
                 knapSack(c, w, v, n,harf);
                 return 0;
            
}
