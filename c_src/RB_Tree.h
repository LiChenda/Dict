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
} RB_Node;

typedef struct _wordlistnode {
    Word *word;
    struct _wordlistnode *next;
} wordlistnode;

typedef struct _words {
    /* data */
    Word *word;
    struct _wordlistnode *next;
    int len;
} wordlist;


/************************************************************************/

RB_Node **initTree();
void insert_word(char* en,  char* sen);
int modify_word(char*en, char* sen);
Word* search_word(char* en);
wordlist suggest_word(char* en);

/************************************************************************/
void leftRotate(RB_Node **Troot, RB_Node *x);
void rightRotate(RB_Node **Troot, RB_Node *x);
void RB_insert(RB_Node **Troot, RB_Node *z);
void RB_insert_fixup(RB_Node **Troot, RB_Node *z);
int cmpkey(RB_Node *a, RB_Node *b);

void cleanQueen();
void dequene();
void inquene(Word *word);
void chilinquene(RB_Node *root, int deep);
/************************************************************************/




#endif /* ifndef _BR_TREE */
