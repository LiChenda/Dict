#include <stdio.h>
#include <stdlib.h>
#include "RB_Tree.h"


#define N 10000

extern RB_Node *const nil;

void visit(RB_Node* root, int d);

int deep = 0;

int main(int argc, char *argv[])
{

    RB_Node * Troot = nil;
    nil->color = BLACK;

    RB_Node array[N];
    int i;
    for (i = 0; i < N; ++i) {
        array[i].testnum = rand();
    }
    for (i = 0; i < N; ++i) {
        RB_insert(&Troot, &array[i]); 
    }

    visit(Troot, 0);
//    printf("%d\n", deep);
    
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
