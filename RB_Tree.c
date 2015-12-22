#include "RB_Tree.h"
#include <string.h>


RB_Node nill;
RB_Node *const nil = &nill; 

void leftRotate(RB_Node **Troot, RB_Node *x)
{
    RB_Node* y = x->right;
    x->right = y->left;
    if(y->left != nil)
        y->left->parent = x;
    y->parent = x->parent;
    if(x->parent == nil)
        *Troot = y;
    else if(x == x->parent->left)
        x->parent->left = y;
    else 
        x->parent->right =y;
    y->left = x;
    x->parent = y;
}

void rightRotate(RB_Node **Troot, RB_Node *x)
{
    RB_Node* y = x->left;
    x->left = y->right;
    if(y->right != nil)
        y->right->parent = x;
    y->parent = x->parent;
    if(x->parent == nil)
        *Troot = y;
    else if(x == x->parent->left)
        x->parent->left = y;
    else 
        x->parent->right = y;
    y->right = x;
    x->parent =y;
}

void RB_insert(RB_Node **Troot, RB_Node *z)
{
    RB_Node *y = nil;
    RB_Node *x = *Troot;
    while(x != nil)
    {
        y = x;
        if(cmpkey(z, x) == -1)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;
    if(y == nil)
        *Troot = z;
    else if(cmpkey(z, y) == -1)
        y->left = z;
    else
        y->right = z;
    z->left = nil;
    z->right = nil;
    z->color = RED;
    RB_insert_fixup(Troot, z);

}


int cmpkey(RB_Node *a, RB_Node *b)
{
    return a->testnum > b->testnum ? 1 : -1; 
    // return strcmp(a->word->en, b->word->en); 
}

void RB_insert_fixup(RB_Node **Troot, RB_Node *z)
{
    RB_Node *y;
    while(z->parent->color == RED)
    {
        if(z->parent == z->parent->parent->left)
        {
            y = z->parent->parent->right; 
            if(y->color == RED)
            {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else
            {
                if(z == z->parent->right)
                {
                    z = z->parent;
                    leftRotate(Troot, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(Troot, z->parent->parent);

            }
        }
        else
        {
            y = z->parent->parent->left;  
            if(y->color == RED)
            {
                z->parent->color = BLACK; 
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else{
                if(z == z->parent->left)
                {
                    z = z->parent;
                    rightRotate(Troot, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(Troot, z->parent->parent);

            }
        }
    }
    (*Troot)->color = BLACK;
}


















