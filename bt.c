#include<stdio.h>
#include<stdlib.h>
struct btnode{
    int data;
     struct btnode *left, *right;
};

void preOrder(struct btnode *root){
     if(root){
        printf("%d", root->data);
        preOrder(left->data);
        preOrder(right->data);
     }
}

void inOrder(struct btnode *root){
     if(root){
        inOrder(left->data);
        printf("%d", root->data);
        inOrder(right->data);
     }
}

void postOrder(struct btnode *root){
     if(root){
        postOrder(left->data);
        postOrder(right->data);
        printf("%d", root->data);
     }
}
