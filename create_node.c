#include <stdio.h>
#include "ft_node.h"

void *create_node(void *item)
{
    Node *elem;
    elem = malloc(sizeof(Node));
    if (elem)
    {
            elem->item = item;
            elem->left = 0;
            elem->right = 0;
    }
    return (elem);

}
