//-------------------------Dakota-----------------------------//
#include <stdio.h>
#include <stdlib.h>
void keyEncoder(char *inputText, int key);
void keyDecoder(char *inputText, int key);
void keyFinder(char *inputText, int limit, int *keyf);


int main(){
    char inputText[1000];
    int key = 0;        //hardcoded atm
    int *keyf;
    keyf = &key;
    int i;
    int limit;
    int answer;
    printf("          Welcome to the Dakota Encoder/Decoder\n\nMy name is not Dakota but I found the wordplay slightly amusing\n\n");
    printf("1) Encrypt with key \n2) Decrypt with key \n3) Decrypt without key (only works for sentences containing 'the')\n");
    //scanf("%d", &answer);
    answer = 2;
    if(answer > 3 || answer < 1)
        return 0;
    
    switch(answer){
        case 1: printf("\nPlease enter the text into 'input.txt'\n"); printf("What is the key? "); scanf("%d", &key); break;
        case 2: printf("\nPlease enter the encrypted code into 'input.txt'\n"); printf("What is the key? "); scanf("%d", &key); break;
        case 3: printf("\nPlease enter the encrypted code into 'input.txt'\n"); break;
    }
        if(key > 26 || key < 0){
            return 0;
        }
    key = 12;    
        
    FILE *input/*, output*/;
    input = fopen("input.txt", "r");
        if(input == NULL){
            perror("fopen()");
            return 0;
        }
        
    for(i = 0; i < 100; i++){       //resets all string values to 0
        inputText[i] = 0;
    }

    for(i = 0; feof(input) == 0; i++){          //scans file to inputText string
        char *c;
        c = &inputText[i];
        fscanf(input, "%c", c);
        limit = i;
    }
    
    
    switch(answer){
        case 1: keyEncoder(inputText, key);
                printf("\nDecoded: ");
                
                for (i = 0; i <= 99; i++)
                    printf("%c ", inputText[i]);
                break;
                
        case 2: printf("\nInput  : ");
                for (i = 0; i <= 99; i++)
                    printf("%c ", inputText[i]);
                printf("\n");
                printf("Key    : %d", key);
                keyDecoder(inputText, key);
                printf("\nDecoded: ");
                
                for (i = 0; i <= 99; i++)
                    printf("%c ", inputText[i]);
                break;
                
        case 3: printf("\nInput  : ");
                for (i = 0; i <= 99; i++)
                    printf("%c ", inputText[i]);
                printf("\n");
                
                keyFinder(inputText, limit, keyf);
                if(key < 0)
                    key += 26;
                printf("Key    : %d", key);
                
                keyDecoder(inputText, key);
                printf("\nDecoded: ");
                
                for (i = 0; i <= 99; i++)
                    printf("%c ", inputText[i]);
                break;
    }
}


//-----------------------------keyFinder-----------------------------------------------------//
void keyFinder(char *inputText, int limit, int *keyf){
    int n;
    for(n = 0; n < limit; n++){
        
        if((inputText[n + 1] == inputText[n] - 12) || (inputText[n + 1] == inputText[n] + 14))
            if((inputText[n + 2] == inputText[n] - 15) || (inputText[n + 2] == inputText[n] + 11)){
                *keyf = 'T' - inputText[n];
                return;
            
            }
    }
}


//-----------------------------keyEncoder------------------------------------//

void keyEncoder(char *inputText, int key){
    int n = 0;
    while(((inputText[n] >= 'A') && (inputText[n] <= 'Z')) || (inputText[n] == ' ')){
        if(inputText[n] == ' '){
            inputText[n] = inputText[n] + key - 26;
        }
        inputText[n] = inputText[n] - key;
        if(inputText[n] < 'A'){
           inputText[n] = inputText[n] + 26;
        }else if(inputText[n] > 'Z'){
            inputText[n] = inputText[n] - 26;
        }
        n++;
    }   
}

//-----------------------------keyDecoder-----------------------------------//

void keyDecoder(char *inputText, int key){
    int n = 0;
    while(((inputText[n] >= 'A') && (inputText[n] <= 'Z')) || (inputText[n] == ' ') || (inputText[n] == ':') || (inputText[n] == ',') || (inputText[n] == 96) || (inputText[n] == '.') ){ 
        if(inputText[n] > 'Z' || inputText[n] < 'A'){
            inputText[n] = inputText[n] - key - 26;
        }
        inputText[n] = inputText[n] + key;
        if(inputText[n] < 'A'){
            inputText[n] = inputText[n] + 26;
        }else if(inputText[n] > 'Z'){
            inputText[n] = inputText[n] - 26; 
        }
        n++;
    }   
}
