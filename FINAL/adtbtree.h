#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// #include "adtbtree.h"
#include "queuelladt.h"

typedef struct tnode
{
  void *dp;
  struct tnode *lc;
  struct tnode *rc;
}TNODE;

typedef struct btree
{
  TNODE *root;
  int  count;
  bool(*compare)(void *, void* );
  void (*print)(void*);
}btree;

btree* createtree(bool(*compare)(void *, void* ),void (*print)(void*))
{
  btree *t = (btree*)malloc(sizeof(btree));
  if(!t)
    return NULL;
  t->root = NULL;
  t->count = 0;
  t->compare = compare;
  t->print = print;
  return t;
}

bool insert_tree_node(btree *t, void *dp)
{
  TNODE *newnode, *traverse, *parent;
  int ch;
  traverse = t->root;
  while(traverse)
    {
      printf("Enter 1 for left and 2 for right: ");
      scanf("%d", &ch);
      parent = traverse;
      if(ch == 1)
        traverse = traverse->lc;
      else if(ch == 2)
        traverse = traverse->rc;
      else
        printf("Invalid choice\n");
    }
  newnode = (TNODE*)malloc(sizeof(TNODE));
  if(!newnode)
    return false;
  newnode->dp = dp;
  newnode->lc = NULL;
  newnode->rc = NULL;
  if(!t->root)
    t->root = newnode;
  else if(ch == 1)
    parent->lc = newnode;
  else if(ch == 2)
    parent->rc = newnode;
  t->count++;
  return true;
}

bool find_key(btree *t, TNODE *root, void *pkey)
{
  if(root)
  {
    if(t->compare(root->dp, pkey))
      return true;
    if(root->lc)
    {
      if(find_key(t, root->lc, pkey))
        return true;
    }
    if(root->rc)
    {
      if(find_key(t, root->rc, pkey))
        return true;
    }
  }
  return false;
}

void find_key_freq(btree *t,TNODE *root, int *freq, void *pkey)
{
  if(root)
  {
    if(t->compare(root->dp, pkey))
      (*freq)++;
    if(root->lc)
      find_key(t, root->lc, pkey);
    if(root->rc)
      find_key(t, root->rc, pkey);
  }
}

void preorder_traversal(btree *t, TNODE *root)
{
  if(root)
  {
    t->print(root->dp);
    if(root->lc)
      preorder_traversal(t, root->lc);
    if(root->rc)
      preorder_traversal(t, root->rc);
  }
}

void inorder_traversal(btree *t, TNODE *root)
{
  if(root)
  {
    if(root->lc)
      inorder_traversal(t, root->lc);
    t->print(root->dp);
    if(root->rc)
      inorder_traversal(t, root->rc);
  }
}

void postorder_traversal(btree *t, TNODE *root)
{
  if(root)
  {
    if(root->lc)
      postorder_traversal(t, root->lc);
    if(root->rc)
      postorder_traversal(t, root->rc);
    t->print(root->dp);
  }
}

void no_leaf_node(TNODE *root, int *leaf)
{
  if(root)
  {
    if(!root->lc && !root->rc)
      (*leaf)++;
    if(root->lc)
      no_leaf_node(root->lc, leaf);
    if(root->rc)
      no_leaf_node(root->rc, leaf);
  }
}

int find_tree_height(TNODE *root)
{
  int hl,hr;
  if(root)
  {
    hl = find_tree_height(root->lc);
    hr = find_tree_height(root->rc);
    if(hl > hr)
      return hl + 1;
    else
      return hr + 1;
  }
  return 0;
}

bool  tree_balanced(TNODE *root)
{
  if(root)
  {
    int b = find_tree_height(root->lc) - find_tree_height(root->rc);
    if(b > 1 || b < -1)
      return false;
    return true;
  }
  return true;
}

void key_parent(btree *t, TNODE *root, TNODE **parent, void *pkey)
{
  if(root)
  {
    if(t->compare(root->dp, pkey))
    {
      *parent = root;
      return;
    }
    if(root->lc)
    {
      key_parent(t, root->lc, parent, pkey);
      if(root->lc == *parent && t->compare(root->lc->dp, pkey))
        *parent = root;
    }
    if(root->rc)
    {
      key_parent(t, root->rc, parent, pkey);
      if(root->rc == *parent && t->compare(root->rc->dp, pkey))
        *parent = root;
    }
  }
}

void breath_first_traversal(btree *t)
{
  TNODE *curnode;
  QUEUE *q = createqueue();
  curnode =  t->root;
  while(curnode)
    {
      t->print(curnode->dp);
      if(curnode->lc)
        if(enqueue(q, curnode->lc))
          ;
      if(curnode->rc)
        if(enqueue(q, curnode->rc))
          ;
      if(!qempty(q))
        curnode = (TNODE*)dequeue(q);
      else
        curnode = NULL;
    }
}

void delete_node(TNODE *root)
{
  if(root)
  {
    delete_node(root->lc);
    delete_node(root->rc);
    free(root->dp);
    free(root);
  }
}
bool destroy_btree(btree *t)
{
  TNODE *temp;
  if(t)
  {
    temp = t->root;
    delete_node(temp);
    free(t);
    return true;
  }
  return false;
}


TNODE* create_new_tree(TNODE *root)
{
  TNODE *newnode;
  newnode = (TNODE*)malloc(sizeof(TNODE));
  if(newnode)
  {
    newnode->dp = root->dp;
    newnode->lc = create_new_tree(root->lc);
    newnode->rc = create_new_tree(root->rc);
    return newnode;
  }
  return NULL;
}

btree* copy_binary_tree(btree *t)
{
  btree *newtree = (btree*)malloc(sizeof(btree));
  if(newtree)
  {
    newtree->root = create_new_tree(t->root);
    newtree->count = t->count;
    newtree->compare = t->compare;
    newtree->print = t->print;
    return newtree;
  }
  return NULL;
}
