#include <stdio.h>
#include "txtfind.h"
#include <string.h>


//params: s empty chars array to write the line into
int getLine(char s[]){
  int i = 0;
    
    while((*(s+i) != '\n') && (*(s+i) != '\0')  && (i< LINE)){
       
        i++;
        
    }
    
    return i;
}

int getWord(char w[]){


    int counter = 0;
    while (*w != '\n' && *w != '\t' && *w != ' '&&counter<WORD){
        counter++;
        w++;
    }
    return counter;
    
   
}


int substring(char * str1, char * str2){
     int str1Length = getWord(str1);
    int str2Length = getWord(str2);
    if(str1Length < str2Length){
        return 0;
    }
    int difference = str1Length - str2Length;
    int boolean = 0;
    for (size_t i = 0; i <= difference ; i++){
        if (*str1 == *str2){
            char * p1 = str1 + 1;
            char * p2 = str2 + 1;
            for (size_t j = 1; j < str2Length; j++){
                if (*p1 == *p2){
                    boolean = 1;
                    p1++;
                    p2++;
                }
                else{
                    boolean = 0;
                    break;
                }
            }
        }
        if (boolean==1){
            return boolean;
        }
        str1++;
    }
    return boolean;
}

int similar (char *s, char *t, int n){
    int sLength = getWord(s);
    int tLength = getWord(t);
    if (sLength < tLength){
        return 0;
    }
    int counter = 0;
    int i = 1;
    for (; i <= sLength; i++) {
        if(*t == ' ' || *t == '\n' || *t == '\t'){
            break;
        }
        if(*s == *t){
            s++;
            t++;
        }
        else{
            s++;
            counter++;
        }
    }
   if (i <= sLength){
        counter = counter + sLength - i + 1;
    }
    if (counter > n){
        return 0;
    }
    return 1;
}

void print_lines(char * str) {
char line[LINE] = {0};
    char *P =line;
    int boolean = 1;
    int flag;
    while(boolean){
        while(1){
            flag = scanf("%c",P);
           
            if (*P == '\n') {
                P = line;
                break;
            }
             if(flag == EOF) {
                boolean = 0;
                break;
            }
            P++;
        }
        while (*P!= '\n'){
            int wordLength = getWord(P);
            char word [WORD] = {0};
            char *Pword = word;
            for (size_t i = 0; i < wordLength; i++) {
                *Pword= *P;
                Pword++;
                P++;
            }
           
          
            if (*P == ' ' || *P == '\t')
                P++;
            if (substring(word,str)){
                printf("%s", line);
                P = line;
                break;
            }
             Pword = word;
        }
        P = line;
       
    }
 
    }

void print_similar_words(char * str){
   char line[LINE] = {0};
    char *P =line;
    int boolean = 1;
    int flag;
    while(boolean){
        while(1){
            flag = scanf("%c",P);
           
            if (*P == '\n') {
                P = line;
                break;
            }
             if(flag == EOF) {
                boolean = 0;
                break;
            }
            P++;
        }
        while (*P!= '\n'){
            int wordLength = getWord(P);
            char word [WORD] = {0};
            char *Pword = word;
            for (size_t i = 0; i < wordLength; i++) {
                *Pword= *P;
                Pword++;
                P++;
            }
           
           *Pword = ' ';
            
           Pword = word;
            if (*P == ' ' || *P == '\t')
                P++;
             if (similar(word,str,1)){
                while(*Pword != '\t' && *Pword != '\n' && *Pword != ' '){
                   printf("%c", *Pword);
                    Pword++;
                }
                printf("\n");
            }
            
        }
        P = line;
      
    }
 
}

int main(){


     char word[WORD] = {0};
   char c='\0';
   int i=0;
 while(1){
     scanf("%c",&word[i]);
    if(word[i]==' '){
      scanf("%c",&c);
        break;}
    i++;
 }

 
 if(c=='a')
 print_lines(word);
if(c=='b')
 print_similar_words(word);
return 0;
}