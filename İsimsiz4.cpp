#include <stdio.h>
#include <stdlib.h>
 
struct node{
    int data;
    struct node* next;
};


 
struct node* head;

void push(int data){
 
 
    struct node* newnode = (struct node*) malloc(sizeof(struct node*));
    newnode->data = data;
    newnode->next = head;
 
    head = newnode;
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
 
void print(){
 
    struct node* p;
    p = head;
 
    while(p!=NULL){
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\t");
}
main()
{
 
  head = NULL;
 
  
  
  push(8);
  push(7);
  push(6);
  push(5);
  push(4);
  push(3);
  push(2);
 
  print();
  printf("\n");
  reverse(head);
  print();
 
}
