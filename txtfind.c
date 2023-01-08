#include <stdio.h>
#include "txtfind.h"
#include <string.h>


#define MAIN
#define GETLINE
#define LINE 256
#define WORD 30


int main() {
    char word[WORD];
    char choose;
    getword(word);
    scanf(" %c\n", &choose);
    if (choose == 'a'){
        print_lines(word);
    }
    else if (choose == 'b'){
        print_similar_words(word);
    }
    return 0;
}
//I do
int ggetline(char str[]){
    int index = 0 ;
    char character = '0';

    while(index < LINE){
        int s=scanf("%c", &character);
        if (character == '\n')
        {
            str[index] = '\0';
            break;
        }
        if ( s== EOF)
        {
            str[index] = '\0';
            break;
        }
        str[index]=character;
        index++;
    }
    if(index==LINE){
        index--;
        str[index] = '\0';
    }

    int length_line=strlen(str);
    return length_line;
}

 //I do   
    int getword(char str[]){

    int index = 0 ;
    char character = '0';

    while(index < WORD){
        int s=scanf("%c", &character);
        if (character == '\n' || character == '\t' || character == ' ' )
        {
            str[index]='\0';
            break;
        }
        if(s==EOF){
            str[index]='\0';
            break;
        }
        str[index]=character;
        index++;
    }
    if(index==WORD){
        index--;
        str[index] = '\0';
    }
    int length_word=strlen(str);
    return length_word;
    }
//I do

int help_substring(char *str1, char *str2)
{
    while (*str1 && *str2 && *str1 == *str2) {
        str1++;
        str2++;
    }
    if(*str2==0){
        return 1;
    }
    return 0;
}
int substring( char * str1, char * str2){

    while(*str1){
        while(*str1&& *str1!=*str2){
            str1++;
        }

        if(*str1==0){
        return 0;
        }
        if(help_substring( str1, str2)){
            return 1;
        }
        str1++;
        
    }
    return 0;
}
//i do
int similar (char *s, char *t, int n){
    for(int i=0;i<=n;i++){
        while (*s && *t && *s == *t) {
        s++;
        t++;
        }
        if(*t==0 &&*s==0){
            return 1;
        }
        s++;
    }
    return 0;
}
//I do 
void print_lines(char * str){
    char line[LINE]={0};

    while(ggetline(line)!=0){
        if(substring(line,str)){
            printf("%s\n",line);
        }
    }
}
//i do
void print_similar_words(char * str){
    char word[WORD]={0};

    while(getword(word)!=0){
        if(similar(word,str,1)){
            printf("%s\n",word);
        }
    }
}
