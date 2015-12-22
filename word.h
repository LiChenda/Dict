/*=============================================================================
#
# Filename: word.h
#
# Author: LiChenda
#
# Email: leohust@qq.com
#
# Last modified: 2015-12-22 10:04
#
# Description:
#   this file defines the date type 'word'
#
=============================================================================*/
#ifndef _WORD_H
#define _WORD_H 


typedef struct _Word {
    char* en;
    char* ch;
    char* sentences;
} Word;

void setEn(char *en, Word *word);
void setCh(char *ch, Word *word);
void setSentences(char *sen, Word *word);
Word *createWord(char *en, char *ch, char *sentences);
void deleteWord(Word *todelete);


#endif /* ifndef _WORD_H */
