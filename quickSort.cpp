
#include <time.h>
#include <stdio.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}


int partition(int array[], int low, int high) {
  
 
  int pivot = array[high];
  
  int i = (low - 1);

 
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        
     
      i++;
      
      
      swap(&array[i], &array[j]);
    }
  }


  swap(&array[i + 1], &array[high]);

  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    
  
    int pi = partition(array, low, high);
    
  
    quickSort(array, low, pi - 1);
    
    quickSort(array, pi + 1, high);
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}


int main() {
  int data[] = {1, 2, 3, 4, 5, 6, 7,8,9,10};
  
  int n = sizeof(data) / sizeof(data[0]);
  
  int data1[] = {10, 9, 8, 7, 6, 5, 4,3,2,1};
  
  int n1= sizeof(data) / sizeof(data[0]);
  
  int data2[] = {3, 7, 5, 10,1, 9, 6,2,8,4};
  
  int n2 = sizeof(data) / sizeof(data[0]);
  
  printf("Siralanmamis\n");
  printArray(data, n);
  printf("Siralanmamis\n");
  printArray(data1, n);
  printf("Siralanmamis\n");
  printArray(data2, n);
	clock_t start, end;
    double cpu_time_used;
  quickSort(data, 0, n - 1);
  clock_t start1, end1;
 double cpu_time_used1;
  quickSort(data1, 0, n - 1);
  clock_t start2, end2;
    double cpu_time_used2;
  quickSort(data2, 0, n - 1);
  
  printf("Siralanmis: \n");
  printArray(data, n);
  end1 = clock();
	cpu_time_used1 = ((double) (end1 - start1)) / CLOCKS_PER_SEC;
  printf("Siralanmis: \n");
  printArray(data1, n1);
  end2 = clock();
	cpu_time_used2 = ((double) (end2 - start2)) / CLOCKS_PER_SEC;
 
  printf("Siralanmis: \n");
  printArray(data2, n2);
  end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf(" zaman =%f",cpu_time_used);
    printf(" zaman =%f",cpu_time_used1);
    printf(" zaman =%f",cpu_time_used2);
}
