#include <stdio.h>
#include <conio.h>

struct pair{
		int value;
		int key;
		
};
void goster(struct pair [], int size);
void goster(struct pair ar[], int size)
{
	int i;
			printf("Deger\tAnahtar\n");

	for(i=0; i<size;i++){
		printf("%d\t%d\n",ar[i].value,ar[i].key);
	}
}
void main(){
	int size,i,temp;
	printf("Size girin");
	scanf("%d",&size);
	struct pair hash_table[size];
	printf("elemean gir");
	for(i=0; i<size;i++){
		scanf("%d",&temp);
		hash_table[temp % size].value =temp;
				hash_table[temp % size].key =temp%size;

		
	}
	printf("\n");
	goster(hash_table,size);
	int a = 0;
}


