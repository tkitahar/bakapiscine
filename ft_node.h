#ifndef FT_BTREE_H
# define FT_BTREE_H

typedef struct		bt
{
	struct bt	*left;
	struct bt	*right;
	int		item;
}					Node;

#endif
