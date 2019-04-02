#include <stdio.h>
#include <stdlib.h>
//void rotate(char *letter, int key);
void encoder(char *inputText, int key);
void decoder(char *inputText, int key);

int main(){   
    char inputText[100] = "HELLO THERE";
    int key = 3;        //hardcoded atm
    //char letter[50]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int i;
        
            
    /*rotate(letter, key);       //code to test rotation for decoding
    for (i = 0; i <= 26; i++)
        printf("%c ", letter[i]); */
    
    encoder(inputText, key);
    for (i = 0; i <= 26; i++)
        printf("%c ", inputText[i]);
    
    decoder(inputText, key);
    for (i = 0; i <= 26; i++)
        printf("%c ", inputText[i]);
    
    return 0;
}

//--------------------------------------------------------------------------//

void encoder(char *inputText, int key){
    int n = 0;
    while(((inputText[n] >= 'A') && (inputText[n] <= 'Z')) || (inputText[n] == ' ')){
        if(inputText[n] == ' '){
            inputText[n] = inputText[n] + 1 + key - 26;
        }
        inputText[n] = inputText[n] - 1 - key;
        if(inputText[n] < 'A'){
           inputText[n] = inputText[n] + 26;
        }
        n++;
    }   
}

//--------------------------------------------------------------------------//

void decoder(char *inputText, int key){
    int n = 0;
    while(((inputText[n] >= 'A') && (inputText[n] <= 'Z')) || (inputText[n] == ' ')){ 
        if(inputText[n] == ' '){
            inputText[n] = inputText[n] - 1 - key - 26;
        }
        inputText[n] = inputText[n] + 1 + key;
        if(inputText[n] < 'A'){
            inputText[n] = inputText[n] + 26;
        }else if(inputText[n] > 'Z'){
            inputText[n] = inputText[n] - 26; 
        }
        n++;
    }   
}

//--------------------------------------------------------------------------//
/*
void rotate(char *letter, int key){
    int n;
    for(n = 26; n >= 0; n--){
       letter [n] = letter[n] - 1 - key; 
       
       if(letter[n] < 'A'){
           letter[n] = letter[n] + 26;
       }
    }
}
}
*/





