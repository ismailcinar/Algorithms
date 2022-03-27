#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node {
	int data;
	struct node * next;

};

struct node * head =NULL;
struct node * temp =NULL;
struct node * prev =NULL;

void basaEkle(int veri)
{
	struct node * eleman =(struct node *)malloc(sizeof(struct node));
	eleman->data=veri;
	if(head==NULL){
		head=eleman;
		head->next=NULL;
	}	
	else{
		temp=head;
		head=eleman;
		head->next=temp;
	}
}

void printMiddle(){
	
	struct node * t = head;
	int element =0;
	int i;
	while(t){
	t=t->next;
	element++;
	}
	int middle =element/2;
	t=head;
	for( i=1;i<middle+1;i++){
		t = t->next;
	}
	
		printf("%d",t->data);
	
	
	
}

void listele(){
	system("cls");
	if(head==NULL){
		printf("liste bos eleman yok\n");
		head=NULL;
	}
	else{
		temp=head;
		while(temp->next!=NULL){
			printf("%d ->",temp->data);
			temp=temp->next;
		}printf("%d ",temp->data);
	}
}

int main() {
	
	while(1){
	
	int choose , number;	
	printf("\n\t MENU \n");
		printf("1---->Basa eleman ekle \n");
		printf("2---->Listele \n");
		printf("---->CIKIS \n");
		printf("Seciminizi yapiniz---");
									
	scanf("%d",&choose);
	switch(choose)
	{
		case 1: printf("Basa eklenecek eleman : ");
		scanf("%d",&number);
		basaEkle(number);
		break;
		case 2: listele();
		break;
		
	}
	}
	return 0;
}
