#include<stdio.h>
#include<stdbool.h>
#include <string.h>

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
        int temp[maxsize*2];
        int n = sizeof(arr);
        for(int i=0;i<n;i++){
             temp[i]=arr[i];
        } 
        memcpy(arr,temp,sizeof(temp));
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
    push(44);
    push(11);
    push(43);
    push(10);
    push(45);
    push(12);
    push(44);
    push(11);
    display();
   
}