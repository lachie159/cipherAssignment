//-------------------------Dakota-----------------------------//
#include <stdio.h>
#include <stdlib.h>
void keyEncoder(char *inputText, int key);
void keyDecoder(char *inputText, int key);
void rotDecoder(char *inputText);
void subDecoder(char *inputText, int *wordMap);

int main(){
    char inputText[100];
    int key = 3;        //hardcoded atm
    int i;
    //int wordMap[10];
    
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
        
    }
        printf("\n");

            
    printf("Input  : ");
    for (i = 0; i <= 99; i++)
        printf("%c ", inputText[i]);
        
    printf("\nEncoded: ");
    keyEncoder(inputText, key);
    for (i = 0; i <= 99; i++)
        printf("%c ", inputText[i]);
        
    for(key = 0; key = 25; key++){
        printf("\nDecoded: ");
        keyDecoder(inputText, key);
        for (i = 0; i <= 99; i++)
            printf("%c ", inputText[i]);
    }
    
    
    /*printf("\nWord Map: ");
    for (i = 0; i <= 8; i++)        //change 8 to bigger number, 8 atm to stop '0 0 0 0...'
        printf("%d ", wordMap[i]); */
    
    return 0;
}

//---------------------------------------------rotDecoder-----------------------------------------------------//
/*void rotDecoder(char *inputText){       //similiar to keyDecoder but will run until all the words are real, option to say no this isnt it
    int n = 0;
    int key = 3;
    
    
    
        }

    }
}

*/


//---------------------------------------------subDecoder------------------------------------------------------//
void subDecoder(char *inputText, int *wordMap){
    int c = 0, n;
    
 

    for(n = 0; n < 100; n++){       //finds out how long each word is
        if(inputText[n] < ' '){
            break;
        }else if(inputText[n] != ' '){
            wordMap[c] = wordMap[c] + 1;
        }else{
            c++;
        }
    }
    /* for each time 3 was mapped, turn that word into 'the' (only map first 'the' then assign 'the' to other 3 letter words)
    for(n = 0; n < 20; n+=2){
        if(wordMap[n] == 3){
            oT = inputText[n];
            inputText[n] = 'T';
            oH = inputText[n + 1];
            inputText[n + 1] = 'H';
            oE = inputText[n + 2];
            inputText[n + 2] = 'E';
            break;
        }
    }*/
    /* assign T H and E (THESE WORDS COULD ALSO BE AND SO LATER WILL CHECK THAT E IS THE MOST COMMON) oT
    for(n = 0; n < 100; n++){
        if(inputText[n] == oT){
            inputText[n] = 'T';
        }else if(inputText[n] == oH){
            inputText[n] = 'H';
        }else if(inputText[n] == oE){           //First test and fox and dog did not change to 'the', sus
            inputText[n] = 'E';
    }
    }*/
}
    
    
    




//-----------------------------keyEncoder------------------------------------//

void keyEncoder(char *inputText, int key){
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

//-----------------------------keyDecoder-----------------------------------//

void keyDecoder(char *inputText, int key){
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


