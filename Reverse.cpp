#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

struct node {
	int data;
	struct node * next;

};

struct node * head =NULL;
struct node * temp =NULL;
struct node * prev =NULL;

void sonaEkle(int veri){
	
	struct node * eleman = (struct node *)malloc (sizeof(struct node));
	eleman->data=veri;
	eleman->next=NULL;
	
	if(head==NULL)
	{
		head=eleman;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=eleman;
	}
}


void reverse(struct node* p){
 
    if(p->next == NULL){
 
        head = p;
        return;
    }
 
    reverse(p->next);
    struct node* rev = p->next;
    rev->next = p;
    p->next = NULL;
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

void reverseList()
{
    struct node *prevNode, *curNode;

    if(head != NULL)
    {
        prevNode = head;
        curNode = head->next;
        head = head->next;

        prevNode->next = NULL; 

        while(head != NULL)
        {
            head = head->next;
            curNode->next = prevNode;

            prevNode = curNode;
            curNode = head;
        }

        head = prevNode; 

    }
}


int main() {
	
	  clock_t start, end;
     double cpu_time_used;
	while(1){
	
	int choose , number;	
	printf("\n\t MENU \n");
		printf("1---->Eleman ekle \n");
		printf("2---->Listele \n");
		printf("3---->reverse  \n");
		printf("4---->reverse Recursive \n");
		printf("---->CIKIS \n");
		printf("Seciminizi yapiniz---");
									
	scanf("%d",&choose);
	switch(choose)
	{
		case 1: printf("Basa eklenecek eleman : ");
		scanf("%d",&number);
		sonaEkle(number);
		break;
		case 2: listele();
		break;
		case 4: 
		clock_t start, end;
     	double cpu_time_used;
	 	reverse(head);
		end = clock();
     	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    	printf(" zaman =%f",cpu_time_used);
		break;
		case 3: reverseList();
		end = clock();
     	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    	printf(" zaman =%f",cpu_time_used);
		break;
	}
	}
	return 0;
}
