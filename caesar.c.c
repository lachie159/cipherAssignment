//-------------------------Dakota-----------------------------//
#include <stdio.h>
#include <stdlib.h>
void keyEncoder(char *inputText, int key);
void randEncoder(char *inputText, int key);
void keyDecoder(char *inputText, int key);
void rotDecoder(char *inputText, int limit, int key);


int main(){
    char inputText[100];
    int key = 23;        //hardcoded atm
    int i;
    int limit;
    int answer;
    printf("         Welcome to the Dakota Encoder/Decoder\n\nMy name is not Dakota but I found the wordplay slightly amusing\n\n");
    printf("1) Encrypt with key \n2) Encrypt with random key \n3) Decrypt with key \n4) Decrypt without key (only works for sentences containing 'the')");
    //scanf("%d", &answer);
    answer = 4;
    if(answer > 4 || answer < 1){
        return 0;
    }
    switch(answer){
        case 1: printf("Please enter the encrypted code into 'input.txt'\n"); printf("What is the key? "); scanf("%d", &key); break;
        case 2: printf("Please enter the encrypted code into 'input.txt'");
        case 3: printf("What is the key? "); scanf("%d", &key); break;
    }
        if(key > 26 || key < 1){
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
        printf("%d ", i);
        fscanf(input, "%c", c);
        limit = i;
    } printf("\n");
    
    
    switch(answer){
        case 1: printf("Input  : ");                        //printing
                for (i = 0; i <= 99; i++)
                    printf("%c ", inputText[i]);
        
                printf("\nEncoded: ");
                keyEncoder(inputText, key);
                for (i = 0; i <= 99; i++)
                    printf("%c ", inputText[i]);
        case 4: rotDecoder(inputText, limit, key);
        
                printf("\nDecoded: ");
                keyDecoder(inputText, key);
                for (i = 0; i <= 99; i++){
                    printf("%c ", inputText[i]);}
    }
    
    
    
   
    
    








            
    printf("Input  : ");                        //printing
    for (i = 0; i <= 99; i++)
        printf("%c ", inputText[i]);
        
    printf("\nEncoded: ");
    keyEncoder(inputText, key);
    for (i = 0; i <= 99; i++)
        printf("%c ", inputText[i]);
        
    rotDecoder(inputText, limit, key);
        
    printf("\nDecoded: ");
    keyDecoder(inputText, key);
        for (i = 0; i <= 99; i++){
            printf("%c ", inputText[i]);
    }
}



//---------------------------------------------rotDecoder-----------------------------------------------------//
void rotDecoder(char *inputText, int limit, int key){       //similiar to keyDecoder but will run until all the words are real, option to say no this isnt it
    int n = 0;
    for(n = 0; n < limit; n++){
        
        if(inputText[n + 1] == ' '){
            break;
        }else if(inputText[n + 1] < 'A'){
            inputText[n + 1] = inputText[n + 1] + 26; 
        }else if(inputText[n + 2] == ' '){
            break;
        }else if(inputText[n + 2] < 'A'){
            inputText[n + 2] = inputText[n + 2] + 26;    
        }
        
        if((inputText[n + 1] == inputText[n] - 12) && (inputText[n + 2] == inputText[n] - 15)){
            if('T' > inputText[n]){
                key = inputText[n] - 'T';
                return;
            }
        }else{
            
            
        }  // most frequent is e
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
    while(((inputText[n] >= 'A') && (inputText[n] <= 'Z')) || (inputText[n] == ' ')){ 
        if(inputText[n] == ' '){
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


