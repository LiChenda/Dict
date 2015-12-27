#include "word.h"
#include <stdlib.h>
#include <string.h>


void setstr(char **des, char *src)
{
    if(*des)
        free(*des);
    *des = (char*)malloc((strlen(src) + 1) * sizeof(char));
    strcpy(*des, src);
}

void setEn(char *en, Word *word)
{
    setstr(&(word->en), en);
}


void setSentences(char *sen, Word *word)
{
    setstr(&(word->sentences), sen);
}

Word *createWord(char *en,  char *sentences)
{
    Word *word = (Word*)malloc(sizeof(Word));
    word->en = NULL;
    word->sentences = NULL; 
    setSentences(sentences, word);
    setEn(en, word);
    return word;
}

void deleteWord(Word *todelete)
{
    free(todelete->en);
    free(todelete->sentences);
    free(todelete);
}






