#include <stdlib.h>
#include "ft_node.h"

void *create_node(int v)
{
    Node *elem;
    elem = (Node *)malloc(sizeof(Node));
    if (elem)
    {
            elem->item = v;
            elem->left = (Node *)malloc(sizeof(Node));
            elem->right = (Node *)malloc(sizeof(Node));
    }
    return (elem);

}

int cmpf(int x, int y)
{
    return x - y;
}

void *insert(Node *root, int v)
{
    if (root->item == 0)
        root = create_node(v);

    if (cmpf(root->item, v) < 0)
        insert(root->left, v);
    else
        insert(root->right, v);
    
    return root;

}
