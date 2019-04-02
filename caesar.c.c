#include <stdio.h>
#include <stdlib.h>
void rotate(char *letter); 
void rotate2(char *letter);
void encoder(char *inputText, int key);
void decoderKey(char *inputText, )

int main(){   
    char inputText[100] = "hello";
    int key = 3;        //hardcoded atm
    //char letter[50]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int i;
        
    /*rotate(letter);       //code to test rotation for decoding
    rotate2(letter);
    for (i = 0; i <= 26; i++)
        printf("%c ", letter[i]); */
    
    encoder(inputText, key);
    for (i = 0; i <= 26; i++)
        printf("%c ", inputText[i]);
    
    return 0;
}
void encoder(char *inputText, int key){
    int n = 0;
    while((inputText[n] >= 'A') && (inputText[n] <= 'z')){
        inputText[n] = inputText[n] + key;
        n++;
    }
}


















//--------------------------------------------------------------------------//
void rotate(char *letter){
    int n;
    static int c = 0;
    for(n = 0; n <= (25 - c); n++){
        letter[n] = letter[n + 1 + c];
    }
    c++;
}

void rotate2(char *letter){
    int n;
    int d = 0;
    static int c = 0;
    for(n = 26; n >= (26 - c); n--){
        letter[n] = letter['A' + c + d];
        d--;
    }
}