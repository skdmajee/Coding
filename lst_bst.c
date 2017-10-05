
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
 *  subtree(List):
 *    // The base Case
 *    if Len(list) == 1:
 *      create Node with NULL left and right
 *      return node
 *    else:
 *       root = Create Node(List[1])
 *       Left-List = CreateLeftList(List[1].val, List)
 *       root->left = subtree(Left.list)
 *       Right-List = CreateLeftList(List[1].val, List)
 *       root->right = subtree(Left.list)
 *       return (root)
 *
 */

struct tnode {
  int data;
  struct tnode *left;
  struct tnode *right;
}tnode;

struct tlist {
  int idx;
  int len;
  int *ta;
}tlist;


#define LEFT 2
#define RIGHT 3


int ta[6]={10,5,1,7,40,50};

struct tnode *newNode(int v)
{
  struct tnode *t;

  t = malloc(sizeof (struct tnode));
  if (t) {
    memset(t, 0, sizeof(*t));
    t->data = v;
  }
  printf("====>>NODE:(%p) %2d\n", t, t->data);
  return (t);
}

void dumpList(struct tlist *tl)
{
  int i,j;

  printf("List: (%p)\n", tl);
    printf("\t @idx %1d\n", tl->idx);
    printf("\t @len %1d\n", tl->len);
    printf("\t vals [ ");
    j = tl->idx;
    for (i=0; i < tl->len; i++, j++)
      printf("%2d ", tl->ta[j]);
    printf (" ]\n");
}

struct tlist *
createList(struct tlist *list, int direction)
{
  struct tlist *new;
  int v;
  int i, j;
  int found=0;

  printf("(%s): list(%p) direction(%s)\n",__func__, list, (direction==RIGHT?"RIGHT":"LEFT"));

  new = malloc(sizeof(*new));
  memset(new, 0, sizeof(*new));

  v=list->ta[list->idx];
  new->ta = list->ta;
  printf("(%s): v(%2d) idx(%2d) len(%2d)\n", __func__, v, list->idx, list->len);

  switch (direction){

    case LEFT:
      i = (list->idx); 
      for (j=1; i<list->len;  j++) {
        if (v > list->ta[i+j]){
          new->len++;
          found = 1;
        } else { 
          // There is no more left
          if (found) 
            new->idx = list->idx + 1;
          break;
        }
      }
      break;

    case RIGHT:
      i = (list->idx); 
      for (j=1; j<list->len; j++) {
        if ( v < list->ta[i+j]) {
          new->idx = j+i;
          new->len = list->len - j;
          found = 1;
          break;
        }
      }

      break;

  }

  dumpList(new);
  return (new);
}



struct tnode * 
//subtree_util(struct tnode *root, struct tlist *list)
subtree_util(struct tlist *list)
{
  struct tnode *t, *tt;
  struct tlist *rList, *lList;
  int v;

  // Base Case
  if (list->len == 1) {
    v = list->ta[list->idx];
    t = newNode(v);
  } else {
    // Head-tail case
    v = list->ta[list->idx];
    t = newNode(v);
    if (t == NULL)
      return t;
    //Create left list
    lList = createList(list, LEFT);
    rList = createList(list, RIGHT);
    if (lList->len) {
      t->left = subtree_util(lList);
      tt = t->left;
      printf("\t %2d->(LEFT) %2d\n", t->data, tt->data);
    }
    if (rList->len) {
      t->right = subtree_util(rList);
      tt = t->right;
      printf("\t %2d->(RIGHT) %2d\n", t->data, tt->data);
    }
  }
  return (t);
}

struct tnode * 
bstCreate(struct tlist *list)
{
  struct tnode *root;
  struct tlist *rList, *lList;
  int v;

  // Base Case
  if (list->len == 1) {
    v = list->ta[list->idx];
    root = newNode(v);
    return (root);
  } else {
    // Head-tail case
    v = list->ta[list->idx];
    root = newNode(v);
    //Create left list
    lList = createList(list, LEFT);
    rList = createList(list, RIGHT);
    if (lList->len) {
      root->left = subtree_util(lList);
      printf("\t %2d->(LEFT) %2d\n", root->data, root->left->data);
    }
    if (rList->len) {
      root->right = subtree_util(rList);
      printf("\t %2d->(RIGHT) %2d\n", root->data, root->right->data);
    }

    return(root);

  }
} 


struct tnode *createTree()
{
  int size = sizeof(ta)/sizeof(int);
  struct tlist tlist;
  struct tnode *root;

  
  //Initialize the list
  tlist.idx=0;
  tlist.len = size;
  tlist.ta = ta;
  dumpList(&tlist);
  root = bstCreate(&tlist);
  return(root);
}

void preorder(struct tnode *t)
{
  if (t == NULL) return;
  printf("%2d ", t->data);
  preorder(t->left);
  preorder(t->right);

}

int main() {

  struct tnode *root;

  root = createTree();
  printf("\n   ROOT (%p) \n", root);
  printf("\n\n");
  preorder(root);
  printf("\n\n");

}


