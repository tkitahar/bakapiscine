#include <stdio.h>
#include "ft_node.h"

void *insert(Node *root, int v);

Node *t;
Node *x;

int main(void)
{
    int n;
    scanf("%d", &n);
    
    int i;
    for (i=0; i++; i < n)
    {
        int value;
        scanf("%d", &value);
        t = insert(x,n);
        if (t)    x = t;
    }

    prefix(x);
        
}
