#include<stdio.h>
#include<stdbool.h>

#define maxsize 5
int end = -1;
int arr[maxsize];

bool isEmpty(){
    return end==-1;
}

bool isFull(){
    return end==maxsize;
}

void push(int item){
    if (isFull())
    {
        printf("Stack is Full");
        return;
    }
    arr[++end]=item;
}

bool pop(){
    if(isEmpty()){
        printf("Stack is Empty");
        return false;
    }
    end--;
    return true;
}

int top(){
    return arr[end];
}

void display(){
    printf("\n");
    for(int i=0;i<=end;i++){
        printf("%d ",arr[i]);
    }
}

void main(){
    push(45);
    push(12);
    display();
    pop();
    display();
    push(122);
    display();
    int n = top();
    printf("\n%d ",n);
}