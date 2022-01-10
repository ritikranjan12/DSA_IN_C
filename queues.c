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

int top(){
    return arr[0];
}

void display(){
    printf("\n");
    for(int i=0;i<=end;i++){
        printf("%d ",arr[i]);
    }
}
bool pop(){
    if(isEmpty()){
        printf("Stack is Empty");
        return false;
    }
    int removed = arr[0];
    printf("\nElement deleted or poped is %d",removed);
    for(int i=1;i<sizeof(arr);i++){
        arr[i-1]=arr[i];
    }
    end--;
    return true;
}

void main(){
    push(23);
    push(24);
    push(25);
    push(26);
    push(27);
    push(45);
    display();
    pop();
    display();

}