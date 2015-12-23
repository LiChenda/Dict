#include <stdio.h>
#include <stdlib.h>
#include "RB_Tree.h"


#define N 10000

extern RB_Node *const nil;

void visit(RB_Node* root, int d);

int deep = 0;

int main(int argc, char *argv[])
{

    initTree();
    char en[] = "hello";
    char ch[] = "你好";
    char sen[] = "hello world";
    insert_word(en, ch, sen);
    en[0] = 'y';
    insert_word(en, ch, sen);
    en[1] = 'u';
    insert_word(en, ch, sen);
    en[1] = 'r';
    insert_word(en, ch, sen);


    wordlist a = suggest_word(en);
    
    printf("%s\n", a.word->en);
    return 0;
}


void visit(RB_Node* root, int d)
{
    if(root->left != nil)
        visit(root->left, d + 1);
    if(root->right != nil)
        visit(root->right, d + 1);
    if(d > deep)
    deep = d;

}
