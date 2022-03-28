#include <stdlib.h>
#include <stdio.h>
#include <time.h>
 swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)     
 
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1]){
           	 swap(&arr[j], &arr[j+1]);
           	 int k;
           	 for(k=0; k<20 ;k++){
                	printf("%d\t",arr[k]);
				}
				printf("\n");
		   }
           
              
}
 
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
	int i,sayi;
	srand(time(NULL));
	int num;
	int arr[20];
	for(i=0; i<20;i++){
		sayi = rand()%100 +1;
		arr[i] = sayi;
	}
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("array: \n");
    printArray(arr, n);
    return 0;
}
