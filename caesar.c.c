#include <stdio.h>
#include <stdlib.h>
void rotate(char *letter, int key);
void encoder(char *inputText, int key);
void incrementLetter(char *inputText, int key);

int main(){   
    char inputText[100] = "hello";
    int key = 5;        //hardcoded atm
    //char letter[50]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int i;
        
            
    /*rotate(letter, key);       //code to test rotation for decoding
    for (i = 0; i <= 26; i++)
        printf("%c ", letter[i]); */
    
    incrementLetter(inputText, key);
    for (i = 0; i <= 26; i++)
        printf("%c ", inputText[i]);
    
    return 0;
}


void incrementLetter(char *inputText, int key){
    int n;
    for(n = 0; inputText[n] == 0; n++){
        inputText[n] = inputText[n] - 1 - key;
        if(inputText[n] < 'A'){
           inputText[n] = inputText[n] + 26;
        }
    }
}












//--------------------------------------------------------------------------//

void encoder(char *inputText, int key){
    int n = 0;
    while((inputText[n] >= 'A') && (inputText[n] <= 'z')){
        inputText[n] = inputText[n] - 1 - key;
        n++;
    }
}

//--------------------------------------------------------------------------//

void rotate(char *letter, int key){
    int n;
    for(n = 26; n >= 0; n--){
       letter [n] = letter[n] - 1 - key; 
       
       if(letter[n] < 'A'){
           letter[n] = letter[n] + 26;
       }
    }
}







