/*=============================================================================
#
# Filename: RB_Tree.h
#
# Author: LiChenda
#
# Email: leohust@qq.com
#
# Last modified: 2015-12-22 09:55
#
# Description: 
#   this file defines the red-black tree
#
=============================================================================*/
#ifndef _RB_TREE
#define _RB_TREE 

#include "word.h"

#define RED 1
#define BLACK 0

typedef struct _RB_Node
{
    int color;
    struct _RB_Node *right;
    struct _RB_Node *left;
    struct _RB_Node *parent;
    Word* word;     
    int testnum;
} RB_Node;



void leftRotate(RB_Node **Troot, RB_Node *x);
void rightRotate(RB_Node **Troot, RB_Node *x);
void RB_insert(RB_Node **Troot, RB_Node *z);
void RB_insert_fixup(RB_Node **Troot, RB_Node *z);
int cmpkey(RB_Node *a, RB_Node *b);





#endif /* ifndef _BR_TREE */
