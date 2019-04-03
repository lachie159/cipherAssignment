//-------------------------Dakota-----------------------------//
#include <stdio.h>
#include <stdlib.h>
void encoder(char *inputText, int key);
void decoder(char *inputText, int key);
void subDecoder(char *inputText, int *wordMap);

int main(){   
    char inputText[100] = "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG";
    int key = 1;        //hardcoded atm
    int i;
    int wordMap[10];

            
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
    
    subDecoder(inputText, wordMap);
    
    printf("\nWord Map: ");
    for (i = 0; i <= 10; i++)
        printf("%d ", wordMap[i]);
    
    return 0;
}

//-----------------------------------------------------------------------------------------------------------//

void subDecoder(char *inputText, int *wordMap){
    int c = 0, n;
    
 

    for(n = 0; n < 100; n++){
        if(inputText[n] < ' '){
            break;
        }else if(inputText[n] != ' '){
            wordMap[c] = wordMap[c] + 1;
        }else{
            c++;
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


