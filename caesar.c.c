//-------------------------Dakota-----------------------------//
#include <stdio.h>
#include <stdlib.h>
//void rotate(char *letter, int key);
void encoder(char *inputText, int key);
void decoder(char *inputText, int key);
void subDecoder(char *inputText, char *wordMap);

int main(){   
    char inputText[100] = "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG";
    int key = 1;        //hardcoded atm
    //char letter[50]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int i;
    char wordMap[20];

            
    printf("Input  : ");
    for (i = 0; i <= 99; i++)
        printf("%c ", inputText[i]);
        
    printf("\nEncoded: ");
    encoder(inputText, key);
    for (i = 0; i <= 99; i++)
        printf("%c ", inputText[i]);
        
    printf("\nDecoded: ");
    decoder(inputText, key);
    for (i = 0; i <= 99; i++)
        printf("%c ", inputText[i]);
    
    printf("\nWord Map: ");
    for (i = 0; i <= 99; i++)
        printf("%c ", wordMap[i]);
    
    return 0;
}

//-----------------------------------------------------------------------------------------------------------//

void subDecoder(char *inputText, char *wordMap){
    int c = 0, n;
    
    for(c = 0; c < 100; c++){
        wordMap[c] = 0;   
    }
    
    c = 0;
    
    for(n = 0; n < 100; n++){
        if(inputText[n] == ' '){
            c++;
        }else if((inputText[n] >= 'A') && (inputText[n] <= 'Z')){
            wordMap[c] = wordMap[c] + 1;
        }
    
}

    
    
    
    
    
}







//--------------------------------------------------------------------------//

void encoder(char *inputText, int key){
    int n = 0;
    while(((inputText[n] >= 'A') && (inputText[n] <= 'Z')) || (inputText[n] == ' ')){
        if(inputText[n] == ' '){
            inputText[n] = inputText[n] - 2 + key - 26;
        }
        inputText[n] = inputText[n] + 2 - key;
        if(inputText[n] < 'A'){
           inputText[n] = inputText[n] + 26;
        }else if(inputText[n] > 'Z'){
            inputText[n] = inputText[n] - 26;
        }
        n++;
    }   
}

//--------------------------------------------------------------------------//

void decoder(char *inputText, int key){
    int n = 0;
    while(((inputText[n] >= 'A') && (inputText[n] <= 'Z')) || (inputText[n] == ' ')){ 
        if(inputText[n] == ' '){
            inputText[n] = inputText[n] + 2 - key - 26;
        }
        inputText[n] = inputText[n] - 2 + key;
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


