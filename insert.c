#include "ft_node.h"

int cmpf(void *x, int y);
void prefix(Node *root);

void *insert(Node *root, int v)
{
    if (!root)
    root = create_node(v);

    if (cmpf(root -> item, v) < 0)
        insert(root -> left, v);
    else
        insert(root -> right, v);
    
    return root;

}
