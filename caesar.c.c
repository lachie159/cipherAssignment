//-------------------------Dakota-----------------------------//
#include <stdio.h>
#include <stdlib.h>
void keyEncoder(char *inputText, int key);
void keyDecoder(char *inputText, int key);
void rotDecoder(char *inputText, int limit, int key, char ec);
void subDecoder(char *inputText, int *wordMap);


int main(){
    char inputText[100];
    int letterCount[100];
    int key = 23;        //hardcoded atm
    int i;
    int limit;
    char e, e2, ec;
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
        //printf("%d ", i);
        fscanf(input, "%c", c);
        limit = i;
    } //printf("\n");
    
    

    
    for(i = 0; feof(input) == 0; i++){          //counts how frequently each letter appears
        if(inputText[i] == ' '){
            i++;
        }if(inputText[i] == 'A'){
            letterCount[i] = letterCount[i] + 1;
        }if(inputText[i] == 'B'){
            letterCount[i] = letterCount[i] + 1;
        }if(inputText[i] == 'C'){
            letterCount[i] = letterCount[i] + 1;
        }if(inputText[i] == 'D'){
            letterCount[i] = letterCount[i] + 1;
        }if(inputText[i] == 'E'){
            letterCount[i] = letterCount[i] + 1;
        }if(inputText[i] == 'F'){
            letterCount[i] = letterCount[i] + 1;
        }if(inputText[i] == 'G'){
            letterCount[i] = letterCount[i] + 1;
        }if(inputText[i] == 'H'){
            letterCount[i] = letterCount[i] + 1;
        }if(inputText[i] == 'I'){
            letterCount[i] = letterCount[i] + 1;
        }if(inputText[i] == 'J'){
            letterCount[i] = letterCount[i] + 1;
        }if(inputText[i] == 'K'){
            letterCount[i] = letterCount[i] + 1;
        }if(inputText[i] == 'L'){
            letterCount[i] = letterCount[i] + 1;
        }if(inputText[i] == 'M'){
            letterCount[i] = letterCount[i] + 1;
        }if(inputText[i] == 'N'){
            letterCount[i] = letterCount[i] + 1;
        }if(inputText[i] == 'O'){
            letterCount[i] = letterCount[i] + 1;
        }if(inputText[i] == 'P'){
            letterCount[i] = letterCount[i] + 1;
        }if(inputText[i] == 'Q'){
            letterCount[i] = letterCount[i] + 1;
        }if(inputText[i] == 'R'){
            letterCount[i] = letterCount[i] + 1;
        }if(inputText[i] == 'S'){
            letterCount[i] = letterCount[i] + 1;
        }if(inputText[i] == 'T'){
            letterCount[i] = letterCount[i] + 1;
        }if(inputText[i] == 'U'){
            letterCount[i] = letterCount[i] + 1;
        }if(inputText[i] == 'V'){
            letterCount[i] = letterCount[i] + 1;
        }if(inputText[i] == 'W'){
            letterCount[i] = letterCount[i] + 1;
        }if(inputText[i] == 'X'){
            letterCount[i] = letterCount[i] + 1;
        }if(inputText[i] == 'Y'){
            letterCount[i] = letterCount[i] + 1;
        }if(inputText[i] == 'Z'){
            letterCount[i] = letterCount[i] + 1;
        }
    }
    printf("%d", E);
    printf("\n");
    for(i = 0; e <= 25; e++){
        if(e > e2){
            ec = e;}
        e2 = e;
        e++;
        printf("%c", e);
        printf("\n");
    }
    
            
    //printf("Input  : ");                        //printing
    for (i = 0; i <= 99; i++)
        //printf("%c ", inputText[i]);
        
    //printf("\nEncoded: ");
   // keyEncoder(inputText, key);
    //for (i = 0; i <= 99; i++)
        //printf("%c ", inputText[i]);
        
    rotDecoder(inputText, limit, key, ec);
        
    //printf("\nDecoded: ");
    keyDecoder(inputText, key);
        //for (i = 0; i <= 99; i++)
            //printf("%c ", inputText[i]);
    }
    
    
    
    
    /*printf("\nWord Map: ");
    for (i = 0; i <= 8; i++)        //change 8 to bigger number, 8 atm to stop '0 0 0 0...'
        printf("%d ", wordMap[i]);
    
    return 0;
}*/

//---------------------------------------------rotDecoder-----------------------------------------------------//
void rotDecoder(char *inputText, int limit, int key, char ec){       //similiar to keyDecoder but will run until all the words are real, option to say no this isnt it
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


