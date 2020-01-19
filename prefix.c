#include "ft_node.h"

void prefix(Node *root)
{
    if (root)
    {
        prefix(root->left);
        prefix(root->right);
        printf("%d ", root->item);
    }
       
}
