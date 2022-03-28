#include <stdio.h>
 #include <stdlib.h>
#include <stdio.h>
#include <time.h>
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
 
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
 
void bubbleSort(int arr[], int n)
{
    for (int k = 0; k < n - 1; k++)
    {
        
        for (int i = 0; i < n - 1 - k; i++)
        {
            if (arr[i] > arr[i + 1]) {
                swap(arr, i, i + 1);
               		 int k;
           	 for(k=0; k<20 ;k++){
                	printf("%d\t",arr[k]);
				}
				printf("\n");
		   }
            }
        }
 	
     
    }

 
int main(void)
{
	
    
	int i,sayi;
	srand(time(NULL));
	int num;
	int arr[20];
	for(i=0; i<20;i++){
		sayi = rand()%100 +1;
		arr[i] = sayi;
	}
    int n = sizeof(arr) / sizeof(arr[0]);
 
    bubbleSort(arr, n);
    printArray(arr, n);
 
    return 0;
}
