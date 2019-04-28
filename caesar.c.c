//-------------------------Dakota-----------------------------//
#include <stdio.h>
#include <stdlib.h>
void keyEncoder(char *inputText, int key); // Encodes plain text
void keyDecoder(char *inputText, int key); // Decodes encrypted text with a key
void allDecoder(char *inputText, int key); // Decodes encrypted text when key cant be found
void keyFinder(char *inputText, int limit, int *keyf); // Finds the key of an encrypted message


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
    answer = 1;
    scanf("%d", &answer);
     //-------------------------------------------------------------------------
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
    
    for(i = 0; i < limit; i++){             //converts lowercase letters to uppercase
        if((inputText[i] >= 'a') && (inputText[i] <= 'z')){
            inputText[i] = inputText[i] - 32;}
    }    
    
    
    switch(answer){
        case 1: if(key == 0){
                    key = 3;
                }
                printf("\nKey    : %d", key);
                keyEncoder(inputText, key);
                printf("\nEncoded: ");
                
                for (i = 0; i <= 999; i++)
                    printf("%c ", inputText[i]);
                printf("\n");
                return 0;
                
        case 2: printf("\nInput  : ");
                for (i = 0; i <= limit; i++)
                    printf("%c ", inputText[i]);
                printf("\n");
                printf("Key    : %d", key);
                keyDecoder(inputText, key);
                printf("\nDecoded: ");
                
                for (i = 0; i <= limit; i++)
                    printf("%c ", inputText[i]);
                printf("\n");
                return 0;
                
        case 3: printf("\nInput  : ");
                for (i = 0; i <= limit; i++)
                    printf("%c ", inputText[i]);
                printf("\n");
                
                keyFinder(inputText, limit, keyf);
                if(key < 0){
                    key += 26;
                }
                if(key != 0){
                    printf("Key    : %d", key);
                    keyDecoder(inputText, key);
                printf("\nDecoded: ");
                
                for (i = 0; i < limit; i++)
                    printf("%c ", inputText[i]);
                printf("\n");
                return 0;
                }else{
                    for(key = 1; key < 26; key++){
                        allDecoder(inputText, key);
                        
                        printf("\n");
                        
                        
                        
                        printf("\nDecoded: ");
                        for (i = 0; i < limit; i++)
                            printf("%c ", inputText[i]);
                            printf("\n");
                            
                        keyDecoder(inputText, key);
                        printf("\nDecoded: ");
                        for (i = 0; i < limit; i++)
                            printf("%c ", inputText[i]); 
                    }
                } 
                return 0;
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
    while(((inputText[n] >= 'A') && (inputText[n] <= 'Z')) || (inputText[n] == ' ') || (inputText[n] == ':') || (inputText[n] == ',') || (inputText[n] == '\'') || (inputText[n] == '.') || (inputText[n] == '-')){
        if(inputText[n] > 'Z' || inputText[n] < 'A'){
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
    while(((inputText[n] >= 'A') && (inputText[n] <= 'Z')) || (inputText[n] == ' ') || (inputText[n] == ':') || (inputText[n] == ',') || (inputText[n] == '\'') || (inputText[n] == '.') || (inputText[n] == '-')){ 
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

//-----------------------------allDecoder-----------------------------------//

void allDecoder(char *inputText, int key){
    int n = 0;
    while(((inputText[n] >= 'A') && (inputText[n] <= 'Z')) || (inputText[n] == ' ') || (inputText[n] == ':') || (inputText[n] == ',') || (inputText[n] == '\'') || (inputText[n] == '.') || (inputText[n] == '-')){ 
        if(inputText[n] > 'Z' || inputText[n] < 'A'){
            inputText[n] = inputText[n] - key - 27;
        }
        inputText[n] = inputText[n] + key + 1;
        if(inputText[n] < 'A'){
            inputText[n] = inputText[n] + 26;
        }else if(inputText[n] > 'Z'){
            inputText[n] = inputText[n] - 26; 
        }
        n++;
    }   
    
}

