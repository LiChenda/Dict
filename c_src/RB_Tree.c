#include "RB_Tree.h"
#include <string.h>
#include <stdlib.h>


RB_Node nill;
RB_Node *const nil = &nill; 

RB_Node *rbroot = NULL;


RB_Node **initTree()
{
    rbroot = nil;
    nil->color = BLACK;
    return &rbroot;
}

void insert_word(char* en, char* sen)
{
    Word *word = createWord(en, sen);
    RB_Node* node = (RB_Node*)malloc(sizeof(RB_Node));
    node->word = word;
    RB_insert(&rbroot, node);
}

void modify_word(char*en, char* sen)
{
    Word *word = search_word(en);
    if(word == NULL)
    {
        return;
    }
    else
    {
        setSentences(sen, word);
        return;
    }
}

wordlist head = {NULL, NULL, 0};
wordlistnode* tail = NULL;
void dequene()
{
    if(head.next)
    {
        wordlistnode* tmp = head.next;
        head.next = tmp->next;
        free(tmp);
        head.len --;
    }

}

void chilinquene(RB_Node *root, int deep)
{
    if(root == nil || deep == 0)
        return;
    chilinquene(root->left, deep - 1);
    chilinquene(root->right, deep - 1);
    inquene(root->word);

}


void inquene(Word *word)
{
    wordlistnode *w = (wordlistnode*)(malloc(sizeof(wordlistnode)));
    w->word = word;
    w->next = NULL;
    if(!tail)
        head.next = w;
    else
        tail->next = w;
    tail = w;

    head.len ++;
    if(head.len > 15)
        dequene();
}
void cleanQueen()
{
    while(head.next)
        dequene();
    tail = head.next;
    head.word = NULL;
}

wordlist suggest_word(char* en)
{
    cleanQueen();
    RB_Node *x = rbroot;
    while(x != nil)
    {
        inquene(x->word);
        int cmp = strcmp(en, x->word->en);
        if(!cmp)
        {
            head.word = x->word;
            break;
        }
        if(cmp > 0)
            x = x->right;
        else
            x = x->left;
    }
    if(x != nil)
    {
        chilinquene(x->left, 3);
        chilinquene(x->right, 3);

    }

    return head;
}

Word* search_word(char* en)
{
    RB_Node *x = rbroot;
    while(x != nil)
    {
        int cmp = strcmp(en, x->word->en);
        if(!cmp)
            return x->word;
        if(cmp > 0)
            x = x->right;
        else
            x = x->left;
    }
    return NULL; 
}



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
    //return a->testnum > b->testnum ? 1 : -1; 
    return strcmp(a->word->en, b->word->en) > 0 ? 1 : -1; 
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



















