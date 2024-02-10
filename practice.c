#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int val;
    struct tree *left;
    struct tree *right;
};

struct tree *root;

void inorder(struct tree *node)
{
    if(node != NULL){
        inorder(node->left);
        printf("%3d ", node->val);
        inorder(node->right);
    }
    
}

void insert(struct tree *node)
{
    struct tree *t1, *t2;

    if(!root)
    {
        root = node;
        return;
    }

    t2 = 0;
    t1 = root;

    while(t1)
    {
        t2 = t1;

        if(t1->val > node->val)
            t1 = t1->left;
        else 
            t1 = t1->right;
    }

    if(t2->val < node->val)
        t2->right = node;
    else 
        t2->left = node;

}


void delete(struct tree *node)
{
    struct tree *t1, *t2;
    struct tree *new_left, *new_right;

    if(node == root)
    {
        printf("\nRoot and Node are same...\n");
        if(root->left != 0 || root->right != 0)
        {
            printf("\nHi..\n");
            new_left = node->left;
            new_right = node->right;

            root->left = root->right = 0;

            free(root);

            root = 0;

            if(new_left != 0)
                insert(new_left);

            if(new_right != 0)
                insert(new_right);
        }
        else 
        {
            printf("\nBye..\n");
            free(root);
            root = 0;
        }
    }
    else 
    {
        t1 = root;
    t2 = 0;

    while(t1 != node)
    {
        t2 = t1;
        if(t1->val > node->val)
            t1 = t1->left;
        else 
            t1 = t1->right;
    }

    if(t2->left == node)
        t2->left = 0;
    else 
        t2->right = 0;

    new_left = node->left;
    new_right = node->right;

    free(node);

    if(new_left != 0)
        insert(new_left);

    if(new_right != 0)
        insert(new_right);
    }

    printf("\n");
    inorder(root);
}
/*
    This is entry point functon...
*/
int main(void)
{

    struct tree *node = malloc(sizeof(struct tree));
    struct tree *tmp;


    node->val = 10;
    node->left = node->right = 0;
    insert(node);

    node = (struct tree*) malloc(sizeof(struct tree));
    node->val = 13;
    tmp = node;
    node->left = node->right = 0;
    insert(node);

    node = (struct tree*) malloc(sizeof(struct tree));
    node->val = 7;
    node->left = node->right = 0;
    insert(node);

    node = (struct tree*) malloc(sizeof(struct tree));
    node->val = 8;
    node->left = node->right = 0;
    insert(node);

    node = (struct tree*) malloc(sizeof(struct tree));
    node->val = 6;
    node->left = node->right = 0;
    insert(node);

    node = (struct tree*) malloc(sizeof(struct tree));
    node->val = 11;
    node->left = node->right = 0;
    insert(node);

    node = (struct tree*) malloc(sizeof(struct tree));
    node->val = 14;
    node->left = node->right = 0;
    insert(node);

    inorder(root);
    delete(node);

    

}