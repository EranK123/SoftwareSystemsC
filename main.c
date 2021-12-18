#include <stdio.h>
#include <string.h>
#include "ex3.h"
#define TXT 1024
#define WORD 30

int main(){
    char word[WORD]; 
    char text[TXT];
    for(int i=0; i<WORD; i++){
        scanf("%c", &word[i]);
        if(word[i] == '\n' || word[i] == '\t' || word[i] == ' '){
            word[i] = '\0';
            break;
        }
    }
    for(int i=0; i<TXT; i++){
        scanf("%c", &text[i]);
        if(text[i] == '~'){
            text[i] = '\0';
            break;
        }
    }
    SubString(word, text);
    printf("%c", '\n');
    atbash(word, text);
    printf("%c", '\n');
    anagram(word, text);
    printf("%c", '\n');
    return 0;
}