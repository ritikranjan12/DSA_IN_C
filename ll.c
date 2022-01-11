#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct node
{
    int val;
    struct node *next;
};

struct node *head=NULL;
struct node *tail = NULL;
int size=0;

void insertathead(int x){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->val=x;
    temp->next=head;
    head=temp;

    if (tail==NULL)
    {
        tail=head;
    }
    size++;
    
}

void insertatTail(int x){
    if(tail==NULL){
        insertathead(x);
    }
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->val=x;

    tail->next=temp;
    tail=temp;
    tail->next=NULL;
    size++;

}

void insert(int index,int val){
    if(index==0){
        insertathead(val);
    }
    if(index==size){
        insertatTail(val);
    }
    struct node *temp;
    temp=head;
    index--;
    while(index--){
        temp=temp->next;
    }
    struct node *ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->val=val;
    ptr->next=temp->next;
    temp->next=ptr;
    size++;

}

void deleteathead(){
    printf("Node to be deleted is %d \n",head->val);
    head=head->next;
    size--;
}

void display(){
    struct node *temp;
    temp=head;
    while(temp!=NULL){
        printf(" %d ->",temp->val);
        temp=temp->next;
    }
    printf(" END \n");
}

void deleteattail(){
    if(size<=1){
        deleteathead();
    }
    struct node *temp;
    temp=head;
    while (temp->next->next!=NULL){
        temp=temp->next;
    }
    printf("Node to be deleted is %d \n",tail->val);
    tail=temp;
    tail->next=NULL;
    size--;
    
}

void main(){
    insertathead(5);
    insertathead(4);
    insertathead(3);
    insertathead(2);
    insertathead(1);
    display();
    insertatTail(6);
    display();
    deleteathead();
    display();
    deleteattail();
    display();
    insert(2,44);
    display();


}

