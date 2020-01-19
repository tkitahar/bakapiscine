#include <stdio.h>
#include "ft_node.h"

void *insert(Node *root, int v);

Node *t;
Node x;

void prefix(Node *root)
{
    if (root->item != 0)
    {
        prefix(root->left);
        prefix(root->right);
        printf("%d ", root->item);
    }
       
}

int main(void)
{
    /*int n;
    scanf("%d", &n);
    
    int i;
    for (i=0; i++; i < n)
    {
        int value;
        scanf("%d", &value);*/
    int i = 0;
    int num[7] = {1,4,2,9,3,5,6};
    for (i=0; i++; i < 7)
    {
        int value = num[i];
        t = insert(&x,value);
        if (t->item != 0)    x = *t;
    }

    prefix(&x);
        
}
