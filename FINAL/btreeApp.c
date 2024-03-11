#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "adtbtree.h"

bool compare(void *dp1, void *dp2)
{
  if(*(int *)dp1 == *(int *)dp2)
    return true;
  return false;
}

void print(void *dp)
{
  printf("%d\t", *(int *)dp);
}

int main()
{
  btree *t = createtree(compare, print);
    btree *newt;
  if(!t)
    return 1;
  int *din,ch,leaf=0,freq=0;
  TNODE *p;
  while(1)
    {
      printf("Enter you choice :\n 1-insert \n2-search \n3-freq of key \n4-no. of nodes \n5-tree traversal \n6-Balanced tree \n7-parent of key \n8-copy tree \n9-Destroy tree\n");
      scanf("%d", &ch);
      switch(ch)
        {
          case 1:
            din = (int *)malloc(sizeof(int));
            if(!din)
              break;
            printf("Enter the data to be inserted: ");
            scanf("%d", din);
            if(insert_tree_node(t, din))
              printf("Inserted\n");
            else
              printf("Not inserted\n");
            break;
          case 2:
            printf("Enter the data to be searched: ");
            scanf("%d", &ch);
            if(find_key(t, t->root, &ch))
              printf("Found\n");
            else
              printf("Not found\n");
            break;
          case 3:
            printf("Enter the key to be searched: ");
            scanf("%d", &ch);
            find_key_freq(t, t->root, &freq, &ch);
            printf("Frequency of key is: %d\n",freq);
            break;
          case 4:
            leaf = 0;
            no_leaf_node(t->root, &leaf);
            printf("Total No. of nodes : %d\n",t->count);
            printf("No. of leaf nodes are: %d\n", leaf);
            printf("Total No. internal of nodes : %d\n",t->count-(leaf));
            break;
          case 5:
            if(t->count == 0)
            {
              printf( "Tree is empty\n");
              break;
            }
            printf("Enter your choice :\n 1-preorder \n2-inorder \n3-postorder\n");
            scanf("%d", &ch);
            switch(ch)
              {
                case 1:
                  preorder_traversal(t, t->root);
                  break;
                case 2:
                  inorder_traversal(t, t->root);
                  break;
                case 3:
                  postorder_traversal(t, t->root);
                  break;
                default:
                  printf("Invalid choice\n");
              }
          break;
          case 6:
            if(tree_balanced(t->root))
              printf("Tree is balanced\n");
            else
              printf("Tree is not balanced\n");
            break;
          case 7:
            printf("Enter the key to be searched: ");
            scanf("%d", &ch);
            key_parent(t, t->root, &p, &ch);
            if(p)
              printf("Parent of key is: %d\n", *(int *)p->dp);
            else
              printf("Parent of key doesn't exists\n");
            break;
          case 8:
          
            newt = (btree*)copy_binary_tree(t);
            if(newt)
              printf("Tree copied\n");
            else
              printf("Tree not copied\n");
            break;
          case 9:
            if(destroy_btree(t))
              printf("Tree destroyed\n");
            else
              printf("Tree not destroyed\n");
            return 0;  
        }
    }
  return 0;
}
