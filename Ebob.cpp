#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	 
     clock_t start, end;
     double cpu_time_used;
     
	int ebob;
	int sayi1;
	int sayi2;
	start = clock();
	printf("Birinci sayiyi giriniz ");
	scanf("%d",&sayi1);
	printf("ikinci sayiyi giriniz ");
	scanf("%d",&sayi2);

	for(int i = 2; i < sayi1 && i < sayi2 ; i++){
		if(sayi1 % i == 0 && sayi2 % i == 0){
			
			ebob = i;
		}
	}
	printf("Sayilarin ebobu = %d",ebob);
	 end = clock();
     cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf(" zaman =%f",cpu_time_used);
}
