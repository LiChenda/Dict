/*=============================================================================
#
# Filename: reverse_polish.c
#
# Author: LiChenda
#
# Email: leohust@qq.com
#
# Last modified: 2015-12-18 15:44
#
# Description:  
#
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include "reverse_polish.h"

int m_cursor = 0;

char rightof(char token)
{
    switch(token)
    {
        case '{':
            return '}';
        case '[':
            return ']';
        case '(':
            return ')';
        default:
            return -1;
    }
}

int process(char *str)
{
    initStack();
    int index = 0;
    while(str[index] != '\0')
    {
        char c = str[index];
        switch (c){
            case '(':
            case '[':
            case '{':
                push(c);
                break;
            case ')':
            case ']':
            case '}':
                while(rightof(peek()) == -1 && peek() != EMPTY)
                    putout(pop());
                if(rightof(peek()) == c)
                    pop();
                else
                    return ERR;
                break;
            case '-':
            case '+':
                while(peek() != EMPTY && rightof(peek()) == -1 )
                    putout(pop());
                push(c);
                break;
            case '/':
            case '*':
                if(peek() == EMPTY)
                {
                    push(c);
                    break;
                }
                while(peek() == '/' || peek() == '*')
                    putout(pop());
                push(c);
                break;
            default:
                putout(c);
        }
        index++;
    }
    while(peek() != EMPTY)
    {
        if(rightof(peek()) != -1) 
            return ERR;
        putout(pop());
    }
    putout('\0');
    return 0;
}

void push(char token)
{
    tokenNode *tmp = (tokenNode*)malloc(sizeof(tokenNode));   
    tmp->token = token;
    tmp->next = stack.next;
    stack.next = tmp;
}

char pop()
{
    if (stack.next == null) {
        return EMPTY; 
    }
    tokenNode* tmp = stack.next;
    stack.next = tmp->next;
    char token = tmp->token;
    free(tmp);
    return token;

}

char peek()
{
    if(stack.next == null) 
        return EMPTY; 
    return stack.next->token;
}

void initStack()
{
    stack.next = null;
    stack.token = -1;
    m_cursor = 0;
}

void putout(char token)
{
    output[m_cursor++] = token;
}


