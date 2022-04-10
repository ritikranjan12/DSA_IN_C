#include<stdio.h>
#include<stdlib.h>

static int j=0;
struct node
{
    int val;
    struct node *right;
    struct node *left; 
};

struct node *NewNode(int val){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->val = val;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
} 

int Search(int inorder[],int start,int end,int curr){
    for (int i = start; i <= end; i++)
    {
       if (inorder[i]==curr)
       {
           return i;
       }
       
    }
    return -1;
    
}

struct node *BuildTree(int preorder[],int inorder[],int start,int end){

    if(start > end) return NULL;
    int curr = preorder[j];
    struct node *temp = NewNode(curr);
    j++;
    if(start==end)  return temp;
    int pos = Search(inorder,start,end,curr);
    temp->left = BuildTree(preorder,inorder,start,pos-1);
    temp->right = BuildTree(preorder,inorder,pos+1,end);
    return temp;

}




void preoderTraversal(struct node *root){
    if(root==NULL) return;
    printf("%d ",root->val);
    preoderTraversal(root->left);
    preoderTraversal(root->right);

}



int main(){

    int preorder[] = {1,2,4,3,5};
    int inorder[] = {4,2,1,3,5};
    printf("Hello i am going to call the build tree function \n");
    struct node *root = BuildTree(preorder,inorder,0,4);
    printf("Hello i am going to call the print tree function \n");
    
    preoderTraversal(root);

    return 0;
}