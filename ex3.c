#include <stdio.h>
#include <string.h>
#define TXT 1024
#define WORD 30


int gematria_word(char s[]);
int gematria_text(char c);
int gematria_compute(char c1, char c2);
void SubString(char word[], char text[]);
void atbash(char word[], char text[]);
int gematria_anagram(char s[], char c);
void anagram(char word[], char text[]);
void remove_first(char arr[], int *size);

     
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
//******************************************//
//Q1
int gematria_word(char s[]){
    char c = '0';
    int value_gematria = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++){
        if (s[i] >= 'a' && s[i] <= 'z'){
            c = s[i] - 'a' + 1;
        }
        else if(s[i] >= 'A' && s[i] <= 'Z'){
            c = s[i] - 'A' + 1;
        }else{
            c = 0;
        }
        value_gematria += c;

    }
    return value_gematria;
}
int gematria_text(char c){
    int value_gematria = 0;
        if (c >= 'a' && c <= 'z'){
            c = c - 'a' + 1;
        }
        else if(c >= 'A' && c <= 'Z'){
            c = c - 'A' + 1;
        }else{
            c = 0;
        }
        value_gematria = c;
        return value_gematria;
    }

//**********************************************//
//Q1
void SubString(char word[], char text[]){
    int value_gematria_word = gematria_word(word);
    int len_word = strlen(word);
    int len_text = strlen(text);
    int count=0;
    int value_amount=0;
    int k1=0;
    char txt_print[len_text];
    char final_txt_print[len_text];
    int final=0;
     printf("Gematria Sequences: ");
    for(int j=0; j<len_text; j++){
        for(int i=j; i<len_text; i++){
            int value_i_gematria_text = gematria_text(text[i]);
        if(len_text-j>=len_word){
            
            if (value_i_gematria_text == 0 && count == 0){
                break;

            }else if(value_i_gematria_text == 0 && count > 0){
                txt_print[k1] = text[i];
                value_amount += value_i_gematria_text;
                k1++;
                count++;

            }else if ((value_amount+value_i_gematria_text) < value_gematria_word){
                txt_print[k1] = text[i];
                value_amount += value_i_gematria_text;
                count++;
                k1++;

            }else if((value_amount+value_i_gematria_text) == value_gematria_word){
                txt_print[k1] = text[i];
                value_amount += value_i_gematria_text;
                count++;
                k1++;
                int s = strlen(txt_print);
                // for (int k = 0; k < s; k++) {
                //     printf("%c", txt_print[k]);
                // }
                // printf("~");
                for(int k=0; k<s; k++){
                    final_txt_print[final++] = txt_print[k];
                }
                final_txt_print[final++] = '~';
                memset(txt_print, 0 , sizeof txt_print);
                count=0;
                k1=0;
                value_amount = 0;
                break;

            }else if((value_amount+value_i_gematria_text) > value_gematria_word){
                memset(txt_print, 0, sizeof txt_print);
                k1=0;
                count=0;
                value_amount=0;
                break;
            }
            // else if(text[i] == '~'){
            //     break;
            // }
        }
        }
    }
    for (int k = 0; k < strlen(final_txt_print)-1; k++) {
        printf("%c", final_txt_print[k]);
    }
}

//************************************************************//
//Q2
void atbash(char word[], char text[]){
    int len_text = strlen(text);
    char txt_print[len_text];
    char txt_print_reverse[len_text];
    char word_copy[WORD];
    char word_copy_reverse[WORD];
    char final_txt_print[TXT] = " ";
    int final=0;
    // int len_word_copy = strlen(word_copy);
    int k1=0;
    int k2=0;
    int count1=0;
    int count2=0;
    printf("Atbash Sequences: ");
    for(int j=0; j<len_text; j++){
    strncpy(word_copy_reverse, word, WORD);
        for(int i=j; i<len_text; i++){
            
            int atb_reverse = gematria_compute(word_copy_reverse[strlen(word_copy_reverse)-1], text[i]);
            if (atb_reverse == 1){
                txt_print_reverse[k2] = text[i];
                k2++;
                count2++;
                word_copy_reverse[strlen(word_copy_reverse)-1] = 0;

            }else if (atb_reverse == 0 && strlen(txt_print_reverse) > 0){
                txt_print_reverse[k2] = text[i];
                k2++;
                count2++;
            }else if (atb_reverse == 0 && strlen(txt_print_reverse) == 0){
                count2=0;
                k2=0;
                break;

            }else if(atb_reverse == -1){
                memset(txt_print_reverse, 0, sizeof txt_print_reverse);
                count2=0;
                k2=0;
                break;
            }
            int size_reverse = strlen(word_copy_reverse);
            if (size_reverse == 0){
            //     for (int q = 0; q < strlen(txt_print_reverse); q++){
            //         printf("%c", txt_print_reverse[q]);
            //     }
            //     printf("~");
            // }
            for (int q = 0; q < strlen(txt_print_reverse); q++){
                    final_txt_print[final] = txt_print_reverse[q];
                    final++;
                }
                final_txt_print[final] = '~';
                final++;
        }
        }
    }

    for(int j=0; j<len_text; j++){
        strncpy(word_copy, word, WORD);
        for(int i=j; i<len_text; i++){
            int atb = gematria_compute(word_copy[0], text[i]);
            if (atb == 1){
                txt_print[k1] = text[i];
                k1++;
                count1++;
                memmove(word_copy, word_copy+1, strlen(word_copy));
            }else if (atb == 0 && strlen(txt_print) > 0){
                txt_print[k1] = text[i];
                k1++;
                count1++;

            }else if (atb == 0 && strlen(txt_print) == 0){
                count1=0;
                k1=0;
                break;

            }else if(atb == -1){
                memset(txt_print, 0, sizeof txt_print);
                count1=0;
                k1=0;
                break;
                
            }
            int size_word_copy = strlen(word_copy);
            if(size_word_copy == 0){
            // for (int q = 0; q < strlen(txt_print); q++){
            //         printf("%c", txt_print[q]);
            // }
            // printf("~");
            for (int q = 0; q < strlen(txt_print); q++){
                final_txt_print[final++] = txt_print[q];
                // final++;
            }
            final_txt_print[final] = '~';
            final++;
        }
    }
}
        for (int q = 0; q < strlen(final_txt_print)-1; q++){
                    printf("%c", final_txt_print[q]);
                }
}

// void remove_first(char arr[], int *size){
//     int len = strlen(arr);
//     char word[len];
//     for(int i=0; i<len-1 ; i++){
//         *(arr+i) = *(arr+i+1);
//     }
//     *size--;
// }


int gematria_compute(char c1, char c2){
    int value_gematria = 0;
        if (c1 >= 'a' && c1 <= 'z'){
            c1 = c1 - 'a' + 1;
        }
        else if(c1 >= 'A' && c1 <= 'Z'){
            c1 = c1 - 'A' + 1;
        }else{
            c1 = 0;
        }
        if (c2 == ' '){
            return 0;
        }
        else if (c2 >= 'a' && c2 <= 'z'){
            c2 = c2 - 'a' + 1;
        }
        else if(c2 >= 'A' && c2 <= 'Z'){
            c2 = c2 - 'A' + 1;
        }else{
            c2 = 0;
        }
        value_gematria = c1 + c2;

        if (value_gematria == 27){
            return 1;
        }
        return -1;
    }

//*****************************************************************//
//Q3
void anagram(char word[], char text[]){
    int len_text = strlen(text);
    char word_copy[WORD];
    char word_temp[WORD];
    char print[TXT];
    char final_print[TXT] = " ";
    int final=0;
    printf("Anagram Sequences: ");
    for(int j=0; j<len_text; j++){
        strncpy(word_copy, word, WORD);
        memset(print, 0, sizeof print);
        memset(word_temp, 0, sizeof word_temp);
        int temp = 1;
        int k = 0;
        for(int i=j; ; i++){
           char c = text[i];
           if(c == ' '){
                if (i!=j){
                    print[k++] = c;
                }
                else{
                    break;
                }               
           }else{
               temp = gematria_anagram(word_copy, c);
               if (temp != -1){
                   print[k++] = c;
                   memmove(&word_copy[temp], &word_copy[temp + 1], strlen(word_copy) - temp);
               }
               else{
                   break;
               }
               if(strlen(word_copy) == 0){
                   break;
               }
           }
        }
        print[k] = '\0';
        if (strlen(word_copy) == 0){
            // for (int q = 0; q < strlen(print) || print[q] != '\0'; q++){
            //      printf("%c", print[q]);
            // }
            // printf("~");
            for (int q = 0; q < strlen(print) || print[q] != '\0'; q++){
                final_print[final] = print[q];
                final++;
            }
            final_print[final] = '~';
            final++;
        }      
    }
     for (int q = 0; q < strlen(final_print)-1; q++){
                 printf("%c", final_print[q]);
            }
}

int gematria_anagram(char s[], char c){
    int len = strlen(s);
    for (int i = 0; i < len; i++){
        if (s[i] == c){
            return i;
        }
    }
    return -1;
}