#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create(){
    return NULL;
}
struct node* insert(){
    int val;
    scanf("%d",&val);
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (val==-1){
        return NULL;
    }
    newnode->data=val;
    newnode->left=insert();
    newnode->right=insert();
    return newnode;

}
int Height(struct node *root){
    if (root==NULL){
        return 0;
    }
    int l = Height(root->left);
    int r = Height(root->right);
    return MAX(l,r)+1;
}

int size(struct node *root, int *s){
    if (root==NULL){
        return 0;
    }
    (*s)++;
    size(root->left,s);
    size(root->right,s);
    return *s;
}

void Traverse(struct node *root){
    if (root==NULL){
        return;
    }
    printf("%d ",root->data);
    Traverse(root->left);
    Traverse(root->right);
}


void Search(struct node *root,int val){
    if (root==NULL){
        return;
    }
    if (root->data==val){
        printf("Found the value!\n");
        return;
    }
    Search(root->left,val);
    Search(root->right,val);
}

int main(){
    struct node *root = create();
    root=insert(root);
    Traverse(root);
    int s= 0;
    printf("\nHeight is: %d",Height(root));
    printf("\nSize is: %d\n",size(root,&s));
    Search(root,3);
    return 0;
}
