#ifndef __REVERSE_H_
#define __REVERSE_H_ 

#define EMPTY -1
#define ERR -1
#define null 0
#define MAXLENGTH 1000


typedef struct _tokenNode {
    char token;
    struct _tokenNode *next;
} tokenNode;

tokenNode stack;
char output[MAXLENGTH];

void push(char token);
char pop();
char peek();
void initStack();
int process(char *str);
void putout(char token);
char rightof(char token);

#endif /* ifndef __REVE */
